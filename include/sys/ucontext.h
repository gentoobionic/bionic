/****************************************************************************
 ****************************************************************************
 ***
 ***   This header was automatically generated from a Linux kernel header
 ***   of the same name, to make information necessary for userspace to
 ***   call into the kernel available to libc.  It contains only constants,
 ***   structures, and macros generated from the original header, and thus,
 ***   contains no copyrightable information.
 ***
 ****************************************************************************
 ****************************************************************************/
#ifndef _SYS_UCONTEXT_H
#define _SYS_UCONTEXT_H 1

#include <features.h>
#include <signal.h>
#include <machine/wordsize.h>

#include <machine/sigcontext.h>

#if __WORDSIZE == 64

typedef long int greg_t;

#define NGREG 23

typedef greg_t gregset_t[NGREG];

#define REG_R8 0
#define REG_R9 1
#define REG_R10 2
#define REG_R11 3
#define REG_R12 4
#define REG_R13 5
#define REG_R14 6
#define REG_R15 7
#define REG_RDI 8
#define REG_RSI 9
#define REG_RBP 10
#define REG_RBX 11
#define REG_RDX 12
#define REG_RAX 13
#define REG_RCX 14
#define REG_RSP 15
#define REG_RIP 16
#define REG_EFL 17
#define REG_CSGSFS 18
#define REG_ERR 19
#define REG_TRAPNO 20
#define REG_OLDMASK 21
#define REG_CR2 22

struct _libc_fpxreg
{
 unsigned short int significand[4];
 unsigned short int exponent;
 unsigned short int padding[3];
};

struct _libc_xmmreg
{
 __uint32_t element[4];
};

struct _libc_fpstate
{

 __uint16_t cwd;
 __uint16_t swd;
 __uint16_t ftw;
 __uint16_t fop;
 __uint64_t rip;
 __uint64_t rdp;
 __uint32_t mxcsr;
 __uint32_t mxcr_mask;
 struct _libc_fpxreg _st[8];
 struct _libc_xmmreg _xmm[16];
 __uint32_t padding[24];
};

typedef struct _libc_fpstate *fpregset_t;

typedef struct
 {
 gregset_t gregs;

 fpregset_t fpregs;
 unsigned long __reserved1 [8];
} mcontext_t;

typedef struct ucontext
 {
 unsigned long int uc_flags;
 struct ucontext *uc_link;
 stack_t uc_stack;
 mcontext_t uc_mcontext;
 sigset_t uc_sigmask;
 struct _libc_fpstate __fpregs_mem;
 } ucontext_t;

#else

typedef int greg_t;

#define NGREG 19

typedef greg_t gregset_t[NGREG];

#define REG_GS 0
#define REG_FS 1
#define REG_ES 2
#define REG_DS 3
#define REG_EDI 4
#define REG_ESI 5
#define REG_EBP 6
#define REG_ESP 7
#define REG_EBX 8
#define REG_EDX 9
#define REG_ECX 10
#define REG_EAX 11
#define REG_TRAPNO 12
#define REG_ERR 13
#define REG_EIP 14
#define REG_CS 15
#define REG_EFL 16
#define REG_UESP 17
#define REG_SS 18

struct _libc_fpreg
{
 unsigned short int significand[4];
 unsigned short int exponent;
};

struct _libc_fpstate
{
 unsigned long int cw;
 unsigned long int sw;
 unsigned long int tag;
 unsigned long int ipoff;
 unsigned long int cssel;
 unsigned long int dataoff;
 unsigned long int datasel;
 struct _libc_fpreg _st[8];
 unsigned long int status;
};

typedef struct _libc_fpstate *fpregset_t;

typedef struct
 {
 gregset_t gregs;

 fpregset_t fpregs;
 unsigned long int oldmask;
 unsigned long int cr2;
 } mcontext_t;

typedef struct ucontext
 {
 unsigned long int uc_flags;
 struct ucontext *uc_link;
 stack_t uc_stack;
 mcontext_t uc_mcontext;
 sigset_t uc_sigmask;
 struct _libc_fpstate __fpregs_mem;
 } ucontext_t;

#endif

#endif
