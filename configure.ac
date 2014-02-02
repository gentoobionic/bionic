AC_PREREQ(2.59)
AC_INIT(bionic, 4.1)

AC_CANONICAL_SYSTEM

AC_PROG_CC
AC_PROG_CXX
AC_CHECK_TOOL(OBJCOPY, objcopy, objcopy)

AM_INIT_AUTOMAKE([subdir-objects -Wno-portability])

AM_PROG_AS
AM_PROG_AR

MKDIRP="mkdir -p"
AC_SUBST(MKDIRP)

COMMON_CFLAGS="${CFLAGS}"
COMMON_CFLAGS="${COMMON_CFLAGS} -Wall -fPIC"
COMMON_CFLAGS="${COMMON_CFLAGS} -fno-exceptions -Wno-multichar -fmessage-length=0 -Wno-unused -Winit-self"
COMMON_CFLAGS="${COMMON_CFLAGS} -Wpointer-arith -Werror=return-type -Werror=non-virtual-dtor -Werror=address"
COMMON_CFLAGS="${COMMON_CFLAGS} -Werror=sequence-point -fno-strict-aliasing"
COMMON_CFLAGS="${COMMON_CFLAGS} -DANDROID"

AC_ARG_ENABLE([debug],
[  --enable-debug    Enable debugging symbols and assertions],
[case "${enableval}" in
  yes|"") DEBUG_BIONIC_LIBC=true ;;
  no)     DEBUG_BIONIC_LIBC=false ;;
  *) AC_MSG_ERROR([bad value ${enableval} for --enable-debug]) ;;
esac],[DEBUG_BIONIC_LIBC=false])
AM_CONDITIONAL([DEBUG_BIONIC_LIBC], [test x$DEBUG_BIONIC_LIBC = xtrue])
AC_SUBST(DEBUG_BIONIC_LIBC)
if test x"${DEBUG_BIONIC_LIBC}" = xtrue ; then
  dnl specify -g -O0 after user cflags 
  COMMON_CFLAGS="${COMMON_CFLAGS} -g -O0 -DDEBUG -UNDEBUG"
else
  COMMON_CFLAGS="${COMMON_CFLAGS} -UDEBUG -DNDEBUG"
fi

AC_ARG_ENABLE([linker-debug],
[  --enable-linker-debug    Enable linker debugging],
[case "${enableval}" in
  yes|"") LINKER_DEBUG=true ;;
  no)     LINKER_DEBUG=false ;;
  *) AC_MSG_ERROR([bad value ${enableval} for --enable-linker-debug]) ;;
esac],[LINKER_DEBUG=false])
AM_CONDITIONAL([LINKER_DEBUG], [test x$LINKER_DEBUG = xtrue])
AC_SUBST(LINKER_DEBUG)

AC_ARG_ENABLE([pthread-debug],
[  --enable-pthread-debug    Enable pthread debugging],
[case "${enableval}" in
  yes|"") PTHREAD_DEBUG=true ;;
  no)     PTHREAD_DEBUG=false ;;
  *) AC_MSG_ERROR([bad value ${enableval} for --enable-pthread-debug]) ;;
esac],[PTHREAD_DEBUG=false])
AM_CONDITIONAL([PTHREAD_DEBUG], [test x$PTHREAD_DEBUG = xtrue])
AC_SUBST(PTHREAD_DEBUG)

if test x"${LINKER_DEBUG}" = xtrue ; then
  COMMON_CFLAGS="${COMMON_CFLAGS} -DLINKER_DEBUG=1"
else
  COMMON_CFLAGS="${COMMON_CFLAGS} -DLINKER_DEBUG=0"
fi

COMMON_CFLAGS_X86="-march=i686 -m32"
COMMON_CFLAGS_ARM=""

COMMON_INCLUDES='-nostdinc -I$(call compiler-include-path) -include $(top_srcdir)/libc/arch-$(TARGET_ARCH)/AndroidConfig.h -I$(top_builddir)/include -I$(top_srcdir)/libc/arch-$(TARGET_ARCH)/include -I$(top_srcdir)/libc/include -I$(top_srcdir)/libc/kernel/arch-$(TARGET_ARCH) -I$(top_srcdir)/libc/arch-$(TARGET_ARCH)/include -I$(top_srcdir)/libc/include -I$(top_srcdir)/libc/kernel/common -I$(top_srcdir)/libc/kernel/arch-$(TARGET_ARCH) -I$(top_srcdir)/libm/include -I$(top_srcdir)/libthread_db/include'
COMMON_INCLUDES_X86='-I$(top_srcdir)/libm/include/i387'
COMMON_INCLUDES_ARM='-I$(top_srcdir)/libm/include/arm'

COMMON_LDFLAGS='-Wl,--warn-shared-textrel -Wl,--fatal-warnings -Wl,-no-undefined -nostdlib -nodefaultlibs -nostartfiles -L$(top_builddir)/libc -L$(top_builddir)/libdl -L$(top_builddir)/libm -L$(top_builddir)/libthread_db'
COMMON_LDFLAGS_X86=""
COMMON_LDFLAGS_ARM=""

COMMON_LDLIBS=""
dnl COMMON_LDLIBS_X86='$(shell $(CC) -print-file-name=libgcc_eh.a)'
COMMON_LDLIBS_X86=""
COMMON_LDLIBS_ARM=""

case $host_os in
  *linux*)
  ;;
  *)
  AC_MSG_ERROR([unsupported host os $host_os])
  ;;
esac

case $host_cpu in
  *i?86*)
    TARGET_ARCH=x86
    COMMON_LDFLAGS="${COMMON_LDFLAGS} ${COMMON_LDFLAGS_X86}"
	COMMON_CFLAGS="${COMMON_CFLAGS} ${COMMON_CFLAGS_X86}"
    COMMON_INCLUDES="${COMMON_INCLUDES} ${COMMON_INCLUDES_X86}"
    COMMON_LDLIBS="${COMMON_LDLIBS} ${COMMON_LDLIBS_X86}"
  ;;
  *arm*)
    TARGET_ARCH=arm
    COMMON_LDFLAGS="${COMMON_LDFLAGS} ${COMMON_LDFLAGS_ARM}"
	COMMON_CFLAGS="${COMMON_CFLAGS} ${COMMON_CFLAGS_ARM}"
    COMMON_INCLUDES="${COMMON_INCLUDES} ${COMMON_INCLUDES_ARM}"
    COMMON_LDLIBS="${COMMON_LDLIBS} ${COMMON_LDLIBS_ARM}"
  ;;
  *)
  AC_MSG_ERROR([unsupported host cpu $host_cpu])
  ;;
esac

AC_SUBST(TARGET_ARCH)

AM_CONDITIONAL([TARGET_ARCH_IS_X86],[test x$TARGET_ARCH = xx86])
AC_SUBST(TARGET_ARCH_IS_X86)

AM_CONDITIONAL([TARGET_ARCH_IS_ARM],[test x$TARGET_ARCH = xarm])
AC_SUBST(TARGET_ARCH_IS_ARM)

AM_CONDITIONAL([TARGET_ARCH_IS_X86_OR_ARM],[test x$TARGET_ARCH = xarm || test x$TARGET_ARCH = xx86])
AC_SUBST(TARGET_ARCH_IS_X86_OR_ARM)

AC_ARG_ENABLE([smp],
[  --enable-smp    Enable smp-optimizations],
[case "${enableval}" in
  yes|"") TARGET_CPU_SMP=true ;;
  no)     TARGET_CPU_SMP=false ;;
  *) AC_MSG_ERROR([bad value ${enableval} for --enable-smp]) ;;
esac],[TARGET_CPU_SMP=false])
AM_CONDITIONAL([TARGET_CPU_SMP], [test x$TARGET_CPU_SMP = xtrue])
AC_SUBST(TARGET_CPU_SMP)

AC_ARG_ENABLE([sse2],
[  --enable-sse2    Enable sse2-optimizations],
[if test x"${TARGET_ARCH_IS_X86}" = xtrue ; then
  case "${enableval}" in
    yes|"") ARCH_X86_HAVE_SSE2=true ;;
    no)     ARCH_X86_HAVE_SSE2=false ;;
    *) AC_MSG_ERROR([bad value ${enableval} for --enable-sse2]) ;;
  esac
fi],[ARCH_X86_HAVE_SSE2=false])
AM_CONDITIONAL([ARCH_X86_HAVE_SSE2], [test x$ARCH_X86_HAVE_SSE2 = xtrue])
AC_SUBST(ARCH_X86_HAVE_SSE2)

AC_ARG_ENABLE([ssse3],
[  --enable-ssse3    Enable ssse3-optimizations],
[if test x"${TARGET_ARCH_IS_X86}" = xtrue ; then
  case "${enableval}" in
    yes|"") ARCH_X86_HAVE_SSSE3=true ;;
    no)     ARCH_X86_HAVE_SSSE3=false ;;
    *) AC_MSG_ERROR([bad value ${enableval} for --enable-ssse3]) ;;
  esac
fi],[ARCH_X86_HAVE_SSSE3=false])
AM_CONDITIONAL([ARCH_X86_HAVE_SSSE3], [test x$ARCH_X86_HAVE_SSSE3 = xtrue])
AC_SUBST(ARCH_X86_HAVE_SSSE3)

AC_ARG_ENABLE([tls],
[  --enable-tls    Enable thread-local storage],
[if test x"${TARGET_ARCH}" = xarm ; then
  case "${enableval}" in
    yes|"")
      ARCH_ARM_HAVE_TLS_REGISTER=true
      COMMON_CFLAGS="${COMMON_CFLAGS} -DHAVE_ARM_TLS_REGISTER "
      ;;
    no)     ARCH_ARM_HAVE_TLS_REGISTER=false ;;
    *) AC_MSG_ERROR([bad value ${enableval} for --enable-tls]) ;;
  esac
fi],[ARCH_ARM_HAVE_TLS_REGISTER=false])
AM_CONDITIONAL([ARCH_ARM_HAVE_TLS_REGISTER], [test x$ARCH_ARM_HAVE_TLS_REGISTER = xtrue])
AC_SUBST(ARCH_ARM_HAVE_TLS_REGISTER)

AC_ARG_ENABLE([neon],
[  --enable-neon    Enable NEON SIMD],
[if test x"${TARGET_ARCH}" = xARM ; then
  case "${enableval}" in
    yes|"")
      ARCH_ARM_HAVE_NEON=true 
      ;;
    no)
      ARCH_ARM_HAVE_NEON=false
    ;;
    *) AC_MSG_ERROR([bad value ${enableval} for --enable-neon]) ;;
  esac
fi],[ARCH_ARM_HAVE_NEON=false])
AM_CONDITIONAL([ARCH_ARM_HAVE_NEON], [test x$ARCH_ARM_HAVE_NEON = xtrue])
AC_SUBST(ARCH_ARM_HAVE_NEON)

COMMON_CFLAGS="${COMMON_CFLAGS} ${COMMON_INCLUDES}"

AC_SUBST(COMMON_CFLAGS)
AC_SUBST(COMMON_LDFLAGS)
AC_SUBST(COMMON_LDLIBS)

AC_CONFIG_FILES(
    Makefile
)
AC_OUTPUT
