AC_PREREQ(2.59)
AC_INIT(bionic, 4.1)
AC_PROG_CC
AC_PROG_CXX

AC_CANONICAL_SYSTEM

AM_INIT_AUTOMAKE([subdir-objects -Wno-portability])
AM_PROG_AS
AM_PROG_AR

AC_ARG_ENABLE([debug],
[  --enable-debug    Enable debugging symbols, linker tracing, and assertions],
[case "${enableval}" in
  yes|"") DEBUG_BIONIC_LIBC=true ;;
  no)     DEBUG_BIONIC_LIBC=false ;;
  *) AC_MSG_ERROR([bad value ${enableval} for --enable-debug]) ;;
esac],[DEBUG_BIONIC_LIBC=false])
AM_CONDITIONAL([DEBUG_BIONIC_LIBC], [test x$DEBUG_BIONIC_LIBC = xtrue])
AC_SUBST(DEBUG_BIONIC_LIBC)

COMMON_LDFLAGS='-Wl,-no-undefined -nostdlib -nodefaultlibs -nostartfiles -Wl,--exclude-libs=libgcc.a -L$(top_builddir)'
COMMON_LDFLAGS_X86="-Wl,--exclude-libs=libgcc_eh.a"

COMMON_CFLAGS='-Wall -fPIC -fno-exceptions -Wno-multichar -fmessage-length=0 -Wno-unused -Winit-self -Wpointer-arith -Werror=return-type -Werror=non-virtual-dtor -Werror=address -Werror=sequence-point -fno-strict-aliasing '
COMMON_CFLAGS_X86="-O3 -pipe -fomit-frame-pointer -march=i686 -m32 -UDEBUG -DNDEBUG"
COMMON_CFLAGS_X86_DEBUG="-g -O0 -pipe -march=i686 -m32 -DDEBUG -UNDEBUG"
COMMON_CFLAGS_ARM="-O3 -pipe -march=armv7-a -mfpu=neon"
COMMON_CFLAGS_ARM_DEBUG="-g -O0 -pipe -march=armv7-a -mfpu=neon -DDEBUG -UNDEBUG"

COMMON_INCLUDES='-nostdinc -I$(call compiler-include-path) -include $(top_srcdir)/libc/arch-$(TARGET_ARCH)/AndroidConfig.h -I$(top_srcdir)/libc/arch-$(TARGET_ARCH)/include -I$(top_srcdir)/libc/include -I$(top_srcdir)/libc/kernel/arch-$(TARGET_ARCH) -I$(top_srcdir)/libc/arch-$(TARGET_ARCH)/include -I$(top_srcdir)/libc/include -I$(top_srcdir)/libc/kernel/common -I$(top_srcdir)/libc/kernel/arch-$(TARGET_ARCH) -I$(top_srcdir)/libm/include -I$(top_srcdir)/libthread_db/include'
COMMON_INCLUDES_X86='-I$(top_srcdir)/libm/include/i387'
COMMON_INCLUDES_ARM='-I$(top_srcdir)/libm/include/arm'

case $host_os in
  *linux*)
  ;;
  *)
  AC_MSG_ERROR([unsupported host os $host_os])
  ;;
esac

case $host_cpu in
  *i?86*)
    TARGET_ARCH=x86;
    ARCH_X86_HAVE_SSE2=true;
    ARCH_X86_HAVE_SSSE3=true;
    TARGET_CPU_SMP=true;
    COMMON_LDFLAGS="${COMMON_LDFLAGS} ${COMMON_LDFLAGS_X86}";
    if test x$DEBUG_BIONIC_LIBC = xtrue; then
    	COMMON_CFLAGS="${COMMON_CFLAGS_X86_DEBUG} ${COMMON_CFLAGS}"
    else
    	COMMON_CFLAGS="${COMMON_CFLAGS_X86} ${COMMON_CFLAGS}"
    fi
  ;;
  *arm*)
    TARGET_ARCH=arm;
    ARCH_ARM_HAVE_TLS_REGISTER=true;
    ARCH_ARM_USE_NON_NEON_MEMCPY=true;
    TARGET_CPU_SMP=true;
    if test x$DEBUG_BIONIC_LIBC = xtrue; then
    	COMMON_CFLAGS="${COMMON_CFLAGS_ARM_DEBUG} ${COMMON_CFLAGS}"
    else
    	COMMON_CFLAGS="${COMMON_CFLAGS_ARM} ${COMMON_CFLAGS}"
    fi
    COMMON_INCLUDES="${COMMON_INCLUDES} ${COMMON_INCLUDES_ARM}"
  ;;
  *)
  AC_MSG_ERROR([unsupported host cpu $host_cpu])
  ;;
esac

COMMON_CFLAGS="${COMMON_CFLAGS} ${COMMON_INCLUDES}"

AC_SUBST(TARGET_ARCH)
AC_SUBST(COMMON_CFLAGS)
AC_SUBST(COMMON_LDFLAGS)

AM_CONDITIONAL([TARGET_CPU_SMP],[test x$TARGET_CPU_SMP = xtrue])
AC_SUBST(TARGET_ARCH)

AM_CONDITIONAL([TARGET_ARCH_IS_X86],[test x$TARGET_ARCH = xx86])
AC_SUBST(TARGET_ARCH_IS_X86)
AM_CONDITIONAL([ARCH_X86_HAVE_SSE2],[test x$ARCH_X86_HAVE_SSE2 = xtrue])
AC_SUBST(ARCH_X86_HAVE_SSE2)
AM_CONDITIONAL([ARCH_X86_HAVE_SSSE3],[test x$ARCH_X86_HAVE_SSSE3 = xtrue])
AC_SUBST(ARCH_X86_HAVE_SSSE3)

AM_CONDITIONAL([TARGET_ARCH_IS_ARM],[test x$TARGET_ARCH = xarm])
AC_SUBST(TARGET_ARCH_IS_ARM)
AM_CONDITIONAL([ARCH_ARM_HAVE_TLS_REGISTER],[test x$ARCH_ARM_HAVE_TLS_REGISTER = xtrue])
AC_SUBST(ARCH_ARM_HAVE_TLS_REGISTER)
AM_CONDITIONAL([ARCH_ARM_USE_NON_NEON_MEMCPY],[test x$ARCH_ARM_USE_NON_NEON_MEMCPY = xtrue])
AC_SUBST(ARCH_ARM_USE_NON_NEON_MEMCPY)

AM_CONDITIONAL([TARGET_ARCH_IS_X86_OR_ARM],[test x$TARGET_ARCH = xarm || test x$TARGET_ARCH = xx86])
AC_SUBST(TARGET_ARCH_IS_X86_OR_ARM)

dnl autotools is a bit dumb about this
PLUSPLUS="++"
AC_SUBST(PLUSPLUS)

AC_CONFIG_FILES(
    Makefile
dnl    libc/Makefile
dnl    libc/zoneinfo/Makefile
dnl    libdl/Makefile
dnl    libm/Makefile
dnl    libstdc++/Makefile
dnl    libthread_db/Makefile
dnl    linker/Makefile
)
AC_OUTPUT
