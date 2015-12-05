/*
 * Copyright (C) 2008-2010 The Android Open Source Project
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *  * Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *  * Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT
 * OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */
#include <sys/linux-syscalls.h>
#include <machine/asm.h>

ENTRY(__pthread_clone)
    @ insert the args onto the new stack
#if defined( __thumb__ ) && ! defined( __thumb2__ )
    subs    r1, #4
    mov     r0, r1
    subs    r1, #4
    mov     r3, r1
    adds    r1, #8
#else
    str     r0, [r1, #-4]
    str     r3, [r1, #-8]
#endif

    @ do the system call
    @ get flags

    mov     r0, r2

    @ new sp is already in r1

#if __ARM_EABI__
# if defined( __thumb__ ) && ! defined( __thumb2__ )
    push    {r3}
    mov     r3, sp
    stm     r3!, {r4, r7}
    mov     sp, r3
    pop     {r3}
# else
    stmfd   sp!, {r4, r7}
# endif
    ldr     r7, =__NR_clone
    swi     #0
#else
    swi     #__NR_clone
#endif

    movs    r0, r0
#if __ARM_EABI__
# if defined( __thumb__ ) || defined( __thumb2__ )
    beq     dontunstack
    push    {r3}
    mov     r3, sp
    ldm     r3!, {r4, r7}
    mov     sp, r3
    pop     {r3}
dontunstack:
# else
    ldmnefd sp!, {r4, r7}
# endif
#endif
    blt     __error

#if defined( __thumb__ ) || defined( __thumb2__ )
    movs    r0, r0
    beq     dontbx
    bx      lr
dontbx:
#else
    bxne    lr
#endif

    @ pick the function arg and call address off the stack and jump
    @ to the C __thread_entry function which does some setup and then
    @ calls the thread's start function

#if defined( __thumb__ ) || defined( __thumb2__ )
    mov     r2, sp
    subs    r2, #4
    ldr     r0, [ r2, #0 ]
    subs    r2, #4
    ldr     r1, [ r2, #0 ]
#else
    ldr     r0, [sp, #-4]
    ldr     r1, [sp, #-8]
#endif
    mov     r2, sp          @ __thread_entry needs the TLS pointer
    ldr     r3, =__thread_entry
    bx      r3

__error:
#if defined( __thumb__ ) && ! defined( __thumb2__ )
    movs    r0, #0
    subs    r0, #1
#else
    movs    r0, #-1
#endif
    bx      lr
END(__pthread_clone)


    #
    # This function is defined as:
    #
    #   pid_t  __bionic_clone( int  flags, void *child_stack,
    #                          pid_t *pid, void *tls, pid_t *ctid,
    #                          int  (*fn)(void *), void* arg );
    #
    # NOTE: This is not the same signature than the GLibc
    #       __clone function here !! Placing 'fn' and 'arg'
    #       at the end of the parameter list makes the
    #       implementation much simpler.
    #

ENTRY(__bionic_clone)
    mov     ip, sp
    .save   {r4, r5, r6, r7}

    # save registers to parent stack
#if defined( __thumb__ ) && ! defined( __thumb2__ )
    push    {r3}
    mov     r3, sp
    stm     r3!, {r4, r5, r6, r7}
    mov     sp, r3
    pop     {r3}
#else
    stmfd   sp!, {r4, r5, r6, r7}
#endif

    # load extra parameters
#if defined( __thumb__ ) && ! defined( __thumb2__ )
    push    {r3}
    mov     r3, ip
    ldm     r3!, {r4, r5, r6}
    pop     {r3}
#else
    ldmfd   ip, {r4, r5, r6}
#endif

    # store 'fn' and 'arg' to the child stack
#if defined( __thumb__ ) && ! defined( __thumb2__ )
    subs    r1, #4
    str     r5, [ r1, #0 ]
    subs    r1, #4
    str     r6, [ r1, #0 ]
    adds    r1, #8
#else
    str     r5, [r1, #-4]
    str     r6, [r1, #-8]
#endif

    # system call
    ldr     r7, =__NR_clone
    swi     #0
    movs    r0, r0
    beq     1f

    # in parent, reload saved registers
    # then either exit or error
    #
    ldmfd   sp!, {r4, r5, r6, r7}
#if defined( __thumb__ ) || defined( __thumb2__ )
    movs r0, r0
    beq     dontbx2
    bx      lr
dontbx2:
#else
    bxne    lr
#endif
    ldr     r1, =__set_syscall_errno
    bx      r1

1:  # in the child - pick arguments
#if defined( __thumb__ ) && ! defined( __thumb2__ )
    mov    r2, sp
    subs   r2, #4
    ldr    r0, [ r2, #0 ]
    subs   r2, #4
    ldr    r1, [ r2, #0 ]
    ldr    r2, =__bionic_clone_entry
    bx     r2
#else
    ldr    r0, [sp, #-4]
    ldr    r1, [sp, #-8]
    b      __bionic_clone_entry
#endif
END(__bionic_clone)
