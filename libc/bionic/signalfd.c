/*
 * Copyright (C) 2013 The Android Open Source Project
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

#include <sys/signalfd.h>

/* Despite the fact that our kernel headers define sigset_t explicitly
 * as a 32-bit integer, the kernel system call really expects a 64-bit
 * bitmap for the signal set, or more exactly an array of two-32-bit
 * values (see $KERNEL/arch/$ARCH/include/asm/signal.h for details).
 *
 * Unfortunately, we cannot fix the sigset_t definition without breaking
 * the C library ABI, so perform a little runtime translation here.
 */

extern int     signalfd4(int, const sigset_t *, size_t, int);

typedef union {
    sigset_t   bionic;
    uint32_t   kernel[2];
} kernel_sigset_t;

int signalfd(int fd, const sigset_t *mask, int flags)
{
    kernel_sigset_t in_set;
    in_set.kernel[0] = in_set.kernel[1] = 0;

    in_set.bionic = *mask;

    return signalfd4(fd, (const sigset_t *) &in_set, sizeof(in_set), flags);
}
