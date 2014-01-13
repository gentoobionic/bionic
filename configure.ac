AC_PREREQ(2.59)
AC_INIT(bionic, 4.1)
AC_PROG_CC

AC_CANONICAL_SYSTEM

AM_INIT_AUTOMAKE

LT_INIT

AC_PROG_LIBTOOL

case $host_os in
  *linux*)
  ;;
  *)
  AC_MSG_ERROR([unsupported host os $host_os])
  ;;
esac

case $host_cpu in
  *86*)
  ;;
  *)
  AC_MSG_ERROR([unsupported host cpu $host_cpu])
  ;;
esac

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
