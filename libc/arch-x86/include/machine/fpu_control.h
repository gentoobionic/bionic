@@ -0,0 +1,47 @@
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
#ifndef _FPU_CONTROL_H
#define _FPU_CONTROL_H 1

#include <features.h>

#define _FPU_MASK_IM 0x01
#define _FPU_MASK_DM 0x02
#define _FPU_MASK_ZM 0x04
#define _FPU_MASK_OM 0x08
#define _FPU_MASK_UM 0x10
#define _FPU_MASK_PM 0x20

#define _FPU_EXTENDED 0x300  
#define _FPU_DOUBLE 0x200
#define _FPU_SINGLE 0x0

#define _FPU_RC_NEAREST 0x0  
#define _FPU_RC_DOWN 0x400
#define _FPU_RC_UP 0x800
#define _FPU_RC_ZERO 0xC00

#define _FPU_RESERVED 0xF0C0  

#define _FPU_DEFAULT 0x037f

#define _FPU_IEEE 0x037f

typedef unsigned int fpu_control_t __attribute__ ((__mode__ (__HI__)));

#define _FPU_GETCW(cw) \
	asm volatile("fnstcw %0" : "=m" (*&cw))
#define _FPU_SETCW(cw) \
	asm volatile("fldcw %0" : : "m" (*&cw))

#endif

