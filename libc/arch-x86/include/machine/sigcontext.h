/****************************************************************************
 ****************************************************************************
 ***
 ***   This header was automatically generated from a glibc header
 ***   of the same name, to make information necessary for userspace to
 ***   call into the kernel available to libc.  It contains only constants,
 ***   structures, and macros generated from the original header, and thus,
 ***   contains no copyrightable information.
 ***
 ****************************************************************************
 ****************************************************************************/
#ifndef _MACHINE_SIGCONTEXT_H
#define _MACHINE_SIGCONTEXT_H 1

#include <machine/wordsize.h>

struct _fpreg
{
 unsigned short significand[4];
 unsigned short exponent;
};

struct _fpxreg
{
 unsigned short significand[4];
 unsigned short exponent;
 unsigned short padding[3];
};

struct _xmmreg
{
 __uint32_t element[4];
};

#if __WORDSIZE == 32

struct _fpstate
{

 __uint32_t cw;
 __uint32_t sw;
 __uint32_t tag;
 __uint32_t ipoff;
 __uint32_t cssel;
 __uint32_t dataoff;
 __uint32_t datasel;
 struct _fpreg _st[8];
 unsigned short status;
 unsigned short magic;

 __uint32_t _fxsr_env[6];
 __uint32_t mxcsr;
 __uint32_t reserved;
 struct _fpxreg _fxsr_st[8];
 struct _xmmreg _xmm[8];
 __uint32_t padding[56];
};

#ifndef sigcontext_struct

#define sigcontext_struct sigcontext
#endif

struct sigcontext
{
 unsigned short gs, __gsh;
 unsigned short fs, __fsh;
 unsigned short es, __esh;
 unsigned short ds, __dsh;
 unsigned long edi;
 unsigned long esi;
 unsigned long ebp;
 unsigned long esp;
 unsigned long ebx;
 unsigned long edx;
 unsigned long ecx;
 unsigned long eax;
 unsigned long trapno;
 unsigned long err;
 unsigned long eip;
 unsigned short cs, __csh;
 unsigned long eflags;
 unsigned long esp_at_signal;
 unsigned short ss, __ssh;
 struct _fpstate * fpstate;
 unsigned long oldmask;
 unsigned long cr2;
};

#else

struct _fpstate
{

 __uint16_t cwd;
 __uint16_t swd;
 __uint16_t ftw;
 __uint16_t fop;
 __uint64_t rip;
 __uint64_t rdp;
 __uint32_t mxcsr;
 __uint32_t mxcr_mask;
 struct _fpxreg _st[8];
 struct _xmmreg _xmm[16];
 __uint32_t padding[24];
};

struct sigcontext
{
 unsigned long r8;
 unsigned long r9;
 unsigned long r10;
 unsigned long r11;
 unsigned long r12;
 unsigned long r13;
 unsigned long r14;
 unsigned long r15;
 unsigned long rdi;
 unsigned long rsi;
 unsigned long rbp;
 unsigned long rbx;
 unsigned long rdx;
 unsigned long rax;
 unsigned long rcx;
 unsigned long rsp;
 unsigned long rip;
 unsigned long eflags;
 unsigned short cs;
 unsigned short gs;
 unsigned short fs;
 unsigned short __pad0;
 unsigned long err;
 unsigned long trapno;
 unsigned long oldmask;
 unsigned long cr2;
 struct _fpstate * fpstate;
 unsigned long __reserved1 [8];
};

#endif

#endif
