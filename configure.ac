AC_PREREQ(2.59)
AC_INIT(bionic, 4.1)

AC_CANONICAL_SYSTEM

AC_PROG_CC
AC_PROG_CXX
AC_CHECK_TOOL(OBJCOPY, objcopy, objcopy)

AM_INIT_AUTOMAKE([subdir-objects -Wno-portability])

AM_PROG_AS
AM_PROG_AR

dnl LT_PREREQ([2.4.6])
LT_INIT
AC_PROG_LIBTOOL
AM_PROG_LIBTOOL

MKDIRP="mkdir -p"
AC_SUBST(MKDIRP)

dnl -fno-unwind-tables -fno-asynchronous-unwind-tables 

COMMON_CFLAGS="${CFLAGS}"
COMMON_CFLAGS="${COMMON_CFLAGS} -Wall -fPIC"
COMMON_CFLAGS="${COMMON_CFLAGS} -fno-exceptions -Wno-multichar -fmessage-length=0 -Wno-unused -Winit-self"
COMMON_CFLAGS="${COMMON_CFLAGS} -Wpointer-arith -Werror=return-type -Werror=non-virtual-dtor -Werror=address"
COMMON_CFLAGS="${COMMON_CFLAGS} -Werror=sequence-point -fno-strict-aliasing"
COMMON_CFLAGS="${COMMON_CFLAGS} -DANDROID"

AC_ARG_ENABLE([debug],
[  --enable-debug            Enable debugging symbols and assertions],
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
[  --enable-linker-debug     Enable linker debugging],
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

#  -nodefaultlibs -nostartfiles
COMMON_LDFLAGS='-Wl,-no-undefined -nostdlib -L$(top_builddir)/libc -L$(top_builddir)/libdl -L$(top_builddir)/libm -L$(top_builddir)/libthread_db'
COMMON_LDFLAGS_X86=""
COMMON_LDFLAGS_ARM=""

COMMON_LDLIBS=""
dnl COMMON_LDLIBS_X86='$(shell $(CC) -print-file-name=libgcc_eh.a)'
COMMON_LDLIBS_X86=""
dnl for __aeabi*
COMMON_LDLIBS_ARM="-lgcc"

case $host_os in
  *linux*)
  ;;
  dnl equivalent to 'none'
  *eabi*)
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
[  --enable-smp              Enable SMP optimizations],
[case "${enableval}" in
  yes|"")
     TARGET_CPU_SMP=true
     ;;
  no)
    TARGET_CPU_SMP=false
    ;;
  *) AC_MSG_ERROR([bad value ${enableval} for --enable-smp]) ;;
esac],[TARGET_CPU_SMP=false])
AM_CONDITIONAL([TARGET_CPU_SMP], [test x$TARGET_CPU_SMP = xtrue])
AC_SUBST(TARGET_CPU_SMP)

if test x"${TARGET_CPU_SMP}" = xtrue ; then
  COMMON_CFLAGS="${COMMON_CFLAGS} -DANDROID_SMP=1"
else
  COMMON_CFLAGS="${COMMON_CFLAGS} -DANDROID_SMP=0"
fi

AC_ARG_ENABLE([sse2],
[  --enable-sse2             Enable SSE2 optimizations],
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
[  --enable-ssse3            Enable SSSE3 optimizations],
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
[  --enable-tls              Enable thread-local storage (TLS)],
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
[  --enable-neon             Enable NEON optimizations],
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

AC_ARG_ENABLE([cxx],
[  --enable-cxx              Enable C++ headers and libraries],
[case "${enableval}" in
  yes|"") ENABLE_CXX=true ;;
  no)     ENABLE_CXX=false ;;
  *) AC_MSG_ERROR([bad value ${enableval} for --enable-cxx]) ;;
esac],[ENABLE_CXX=false])
AM_CONDITIONAL([ENABLE_CXX], [test x$ENABLE_CXX = xtrue])
AC_SUBST(ENABLE_CXX)

AC_ARG_ENABLE([headers-only],
[  --enable-headers-only     Only prepare / install header files],
[case "${enableval}" in
  yes|"")
    HEADERS_ONLY=true
    ;;
  no)
    HEADERS_ONLY=false
    ;;
  *) AC_MSG_ERROR([bad value ${enableval} for --enable-headers-only]) ;;
esac],[HEADERS_ONLY=false])
AM_CONDITIONAL([HEADERS_ONLY], [test x$HEADERS_ONLY = xtrue])
AC_SUBST(HEADERS_ONLY)

AC_ARG_ENABLE([kernel-headers],
[  --enable-kernel-headers   Install sanitized kernel headers],
[case "${enableval}" in
  yes|"")
    KERNEL_HEADERS=true
    ;;
  no)
    KERNEL_HEADERS=false
    ;;
  *) AC_MSG_ERROR([bad value ${enableval} for --enable-kernel-headers]) ;;
esac],[KERNEL_HEADERS=false])
AM_CONDITIONAL([KERNEL_HEADERS], [test x$KERNEL_HEADERS = xtrue])
AC_SUBST(KERNEL_HEADERS)

AC_ARG_ENABLE([kh-only],
[  --enable-kh-only          Only install sanitized kernel headers],
[case "${enableval}" in
  yes|"")
    KH_ONLY=true
    KERNEL_HEADERS=true
    HEADERS_ONLY=true
    ;;
  no)
    KH_ONLY=false
    ;;
  *) AC_MSG_ERROR([bad value ${enableval} for --enable-kh-only]) ;;
esac],[KH_ONLY=false])
AM_CONDITIONAL([KH_ONLY], [test x$KH_ONLY = xtrue])
AC_SUBST(KH_ONLY)
AC_SUBST(HEADERS_ONLY)

AM_CONDITIONAL([KERNEL_HEADERS_OR_KH_ONLY], [test x$KERNEL_HEADERS = xtrue || test x$KH_ONLY = xtrue])
AC_SUBST(KERNEL_HEADERS_OR_KH_ONLY)

COMMON_CFLAGS="${COMMON_CFLAGS} ${COMMON_INCLUDES}"

SYSCALLS_ARCH="${TARGET_ARCH}"
if test "${TARGET_ARCH}" = "arm" -a "${CFLAGS/thumb/}" != "${CFLAGS}" ; then
  SYSCALLS_ARCH="thumb"
fi

AC_SUBST(COMMON_CFLAGS)
AC_SUBST(COMMON_LDFLAGS)
AC_SUBST(COMMON_LDLIBS)
AC_SUBST(SYSCALLS_ARCH)

AC_CONFIG_FILES(
    Makefile
)
AC_OUTPUT
