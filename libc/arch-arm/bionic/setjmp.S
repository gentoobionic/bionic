/*	$OpenBSD: setjmp.S,v 1.2 2004/02/01 05:40:52 drahn Exp $	*/
/*	$NetBSD: setjmp.S,v 1.5 2003/04/05 23:08:51 bjh21 Exp $	*/

/*
 * Copyright (c) 1997 Mark Brinicombe
 * Copyright (c) 2010 Android Open Source Project.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. All advertising materials mentioning features or use of this software
 *    must display the following acknowledgement:
 *	This product includes software developed by Mark Brinicombe
 * 4. Neither the name of the University nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

#include <machine/asm.h>
#include <machine/setjmp.h>
#include <machine/cpu-features.h>

/*
 * C library -- setjmp, longjmp
 *
 *	longjmp(a,v)
 * will generate a "return(v)" from the last call to
 *	setjmp(a)
 * by restoring registers from the stack.
 * The previous signal state is restored.
 */

ENTRY(setjmp)
	/* Block all signals and retrieve the old signal mask */
#if defined( __thumb__ ) && ! defined( __thumb2__ )
    push    {r3}
    mov     sp, r3
    stm     r3!, {r0}
    mov     r0, r14
    stm     r3!, {r0}
    mov     sp, r3
    pop     {r3}
#else
    stmfd   sp!, {r0, r14}
#endif
    movs r0, #0x00000000

	bl	PIC_SYM(_C_LABEL(sigblock), PLT)
	mov	r1, r0

#if defined( __thumb__ ) && ! defined( __thumb2__ )
    push    {r3}
    mov     sp, r3
    ldm     r3!, {r0}
    mov     r14, r0
    ldm     r3!, {r0}
    mov     sp, r3
    pop     {r3}
#else
    ldmfd   sp!, {r0, r14}
#endif

	/* Store signal mask */
	str	r1, [r0, #(_JB_SIGMASK * 4)]

	ldr	r1, .Lsetjmp_magic
	str	r1, [r0, #(_JB_MAGIC * 4)]

	/* Store core registers */
	adds    r1, r0
	adds    r1, #(_JB_CORE_BASE * 4)
#if defined( __thumb__ ) || defined( __thumb2__ )
    @ since we're not pushing to the stack pointer, we cannot use push!!!
    stm     r1!, {r4-r7}
    mov     r2, r8
    mov     r3, r9
    mov     r4, r10
    mov     r5, r11
    mov     r6, r12
    mov     r7, r13
    stm     r1!, {r2-r7}
    mov     r2, r14
    stm     r1!, {r2}
#else
	stmia   r1, {r4-r14}
#endif

#ifdef __ARM_HAVE_VFP
	/* Store floating-point registers */
	add     r1, r0, #(_JB_FLOAT_BASE * 4)
	vstmia  r1, {d8-d15}
	/* Store floating-point state */
	fmrx    r1, fpscr
	str     r1, [r0, #(_JB_FLOAT_STATE * 4)]
#endif  /* __ARM_HAVE_VFP */

	movs    r0, #0x00000000
	bx      lr
END(setjmp)

ENTRY(longjmp)
	ldr	r2, .Lsetjmp_magic
	ldr	r3, [r0, #(_JB_MAGIC * 4)]
	cmp	r2, r3
	bne	botch

	/* Fetch signal mask */
	ldr	r2, [r0, #(_JB_SIGMASK * 4)]

	/* Set signal mask */
#if defined( __thumb__ ) && ! defined( __thumb2__ )
    push    {r3}
    mov     r3, sp
    stm     r3!, {r0, r1}
    mov     r0, r14
    stm     r3!, {r0}
    mov     sp, r3
    pop     {r3}
#else
	stmfd	sp!, {r0, r1, r14}
#endif
	sub	sp, sp, #4	/* align the stack */

	mov	r0, r2
	bl	PIC_SYM(_C_LABEL(sigsetmask), PLT)

	add	sp, sp, #4	/* unalign the stack */
#if defined( __thumb__ ) && ! defined( __thumb2__ )
    push    {r3}
    mov     r3, sp
	ldm     r3!, {r0}
	mov     r14, r0
    ldm     r3!, {r0, r1}
    pop     {r3}
#else
    ldmfd   sp!, {r0, r1, r14}
#endif

#ifdef __ARM_HAVE_VFP
	/* Restore floating-point registers */
	add     r2, r0, #(_JB_FLOAT_BASE * 4)
	vldmia  r2, {d8-d15}
	/* Restore floating-point state */
	ldr     r2, [r0, #(_JB_FLOAT_STATE * 4)]
	fmxr    fpscr, r2
#endif /* __ARM_HAVE_VFP */

	/* Restore core registers */
	adds    r2, r0
	adds    r2, #(_JB_CORE_BASE * 4)
#if defined( __thumb__ ) || defined( __thumb2__ )
    @ since we're not popping from the stack pointer, we cannot use pop!!!
    @ have to pop 5 at a time since r0, r1, r2 seem to be used

    @ precompensate r2, pop r10-r14
    adds    r2, r2, #( 6 * 4 )
    ldm     r2!, {r3-r7}
    mov     r14, r7
    mov     r13, r6
    mov     r12, r5
    mov     r11, r4
    mov     r10, r3

    @ precompensate r2, pop r5-r9
    subs    r2, #( (6+5) * 4 )
    ldm     r2!, {r3-r7}
    mov     r9, r7
    mov     r8, r6
    mov     r7, r5
    mov     r6, r4
    mov     r5, r3

    @ precompensate r2, pop r4
    subs    r2, #( 1 * 4 )
    ldm     r2, {r4}
#else
	ldmia   r2, {r4-r14}
#endif

	/* Validate sp and r14 */
#if defined( __thumb__ ) || defined( __thumb2__ )
    mov     r0, sp
    cmp     r0, #0
    beq     botch
    mov     r0, r14
    cmp     r0, #0
#else
	teq	sp, #0
	teqne	r14, #0
#endif
	beq	botch

	/* Set return value */
#if defined( __thumb__ ) || defined( __thumb2__ )
    movs    r0, r1
    bne     bxlr
    movs    r0, #1
bxlr:
    bx      lr
#else
    mov r0, r1
    teq r0, #0x00000000
    moveq   r0, #0x00000001
    bx      lr
#endif

#ifdef __ARM_26__
	mov	r15, r14
#else
	mov	r15, r14
#endif

	/* validation failed, die die die. */
botch:
	bl	PIC_SYM(_C_LABEL(longjmperror), PLT)
	bl	PIC_SYM(_C_LABEL(abort), PLT)
	b	. - 8		/* Cannot get here */

	.align 4
.Lsetjmp_magic:
    .word   _JB_MAGIC_SETJMP

END(longjmp)
