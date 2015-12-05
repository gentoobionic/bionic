/*
 * Copyright (C) 2008 The Android Open Source Project
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
/* unlike our auto-generated syscall stubs, this code saves lr
   on the stack, as well as a few other registers. this makes
   our stack unwinder happy, when we generate debug stack
   traces after the C library or other parts of the system
   abort due to a fatal runtime error (e.g. detection
   of a corrupted malloc heap).
*/

#include <sys/linux-syscalls.h>
#include <machine/asm.h>

#ifndef __NR_tgkill
#define __NR_tgkill  268
#endif

ENTRY(tgkill)
#if defined( __thumb__ ) && ! defined( __thumb2__ )
    mov     r3, sp
    stm     r3!, {r4-r7}
    mov     r4, ip
    mov     r5, lr
    stm     r3!, {r4,r5}
    mov     sp, r3
    ldr     r7, =__NR_tgkill
    swi     #0
    mov     r3, sp
    ldm     r3!, {r4,r5}
    mov     ip, r4
    mov     lr, r5
    ldm     r3!, {r4-r7}
    mov     sp, r3
    mov     r3, lr
    movs    r0, r0
    bpl     0f
    ldr     r3, =__set_syscall_errno
0:
    bx      lr
#else
    stmfd   sp!, {r4-r7, ip, lr}
    ldr     r7, =__NR_tgkill
    swi     #0
    ldmfd   sp!, {r4-r7, ip, lr}
    movs    r0, r0
#if defined( __thumb2__ )
    it      pl
#endif /* defined( __thumb2__ ) */
    bxpl    lr
    b       __set_syscall_errno
#endif
END(tgkill)
