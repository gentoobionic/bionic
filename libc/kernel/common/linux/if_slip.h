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
#ifndef __LINUX_SLIP_H
#define __LINUX_SLIP_H

#define SL_MODE_SLIP 0
#define SL_MODE_CSLIP 1
#define SL_MODE_KISS 4

#define SL_OPT_SIXBIT 2
#define SL_OPT_ADAPTIVE 8

#define SIOCSKEEPALIVE (SIOCDEVPRIVATE)  
#define SIOCGKEEPALIVE (SIOCDEVPRIVATE+1)  
#define SIOCSOUTFILL (SIOCDEVPRIVATE+2)  
#define SIOCGOUTFILL (SIOCDEVPRIVATE+3)  
#define SIOCSLEASE (SIOCDEVPRIVATE+4)  
#define SIOCGLEASE (SIOCDEVPRIVATE+5)  

#endif
