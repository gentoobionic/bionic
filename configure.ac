AC_PREREQ(2.59)
AC_INIT(bionic, 4.1)
AC_PROG_CC
AC_PROG_CXX

AC_CANONICAL_SYSTEM

AM_INIT_AUTOMAKE
AM_PROG_AS

LT_INIT

AC_PROG_LIBTOOL

# -Wl,-no-undefined 
# -L$(top_builddir)/libc/.libs -L$(top_builddir)/libthread_db/.libs -L$(top_builddir)/libdl/.libs
COMMON_LDFLAGS='-Wl,-no-undefined -nostdlib -nodefaultlibs -Wl,--exclude-libs=libgcc.a -L$(top_builddir)'

COMMON_LDFLAGS_X86="-Wl,--exclude-libs=libgcc_eh.a"

case $host_os in
  *linux*)
  ;;
  *)
  AC_MSG_ERROR([unsupported host os $host_os])
  ;;
esac

case $host_cpu in
  *86*)
    TARGET_ARCH=x86;
    ARCH_X86_HAVE_SSE2=true;
    ARCH_X86_HAVE_SSSE3=true;
    TARGET_CPU_SMP=true;
    COMMON_LDFLAGS="${COMMON_LDFLAGS} ${COMMON_LDFLAGS_X86}";
  ;;
  *arm*)
    TARGET_ARCH=arm;
    ARCH_ARM_HAVE_TLS_REGISTER=true;
    ARCH_ARM_USE_NON_NEON_MEMCPY=true;
    TARGET_CPU_SMP=true;
  ;;
  *)
  AC_MSG_ERROR([unsupported host cpu $host_cpu])
  ;;
esac

AC_SUBST(TARGET_ARCH)

AC_SUBST(COMMON_LDFLAGS)

AM_CONDITIONAL([TARGET_CPU_SMP],[test x$TARGET_CPU_SMP = xtrue])
AC_SUBST(TARGET_ARCH)

DEBUG_BIONIC_LIBC="false"
AM_CONDITIONAL(DEBUG_BIONIC_LIBC,[test x$DEBUG_BIONIC_LIBC = xtrue])

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
    libc/Makefile
    libc/zoneinfo/Makefile
    libdl/Makefile
    libm/Makefile
    libstdc++/Makefile
    libthread_db/Makefile
    linker/Makefile
)
AC_OUTPUT
