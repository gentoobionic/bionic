#!/bin/sh

PROJ=bionic

if [ "$(grep "AC_INIT(${PROJ}" configure.ac)" = "" ]; then
  echo "autogen.sh must be run in PWD of ${PROJ} source"
  exit 1
fi

if [ "$1" = clean ]; then
  if [ -e "Makefile" ]; then
    make clean
  fi
  for e in la lo lai o so m4 stamp; do
    rm -f $(find . -name "*.${e}" -type f)
  done
  for e in Makefile.in Makefile depcomp INSTALL config.guess config.sub config.log config.status configure install-sh ltmain.sh missing libtool; do
    rm -f $(find . -name "${e}" -type f -o -type l)
  done
  for e in autom4te.cache .libs .deps; do
    rm -Rf $(find . -name "${e}" -type d)
  done
else
	#	cp libc/Makefile.am.in blah
	#	for arch in arm x86; do
    # a little magic to have automake properly informed of the gensyscalls output
    #_top_builddir=${PWD}
    #_top_scrdir="${0/configure/}"
    #SYSCALLS_TO_COMPILE="$(python ${_top_srcdir}libc/tools/gensyscalls.py ${arch})"
    #SYSCALLS_TO_COMPILE="$(echo ${SYSCALLS_TO_COMPILE})"
    #echo "${SYSTOOLS_TO_COMPILE}"
    #python ${_top_srcdir}libc/tools/sed.py libc/Makefile.am.in libc/Makefile.am "#SYSCALLS_TO_COMPILE_$(echo ${arch} | tr [:lower:] [:upper:])#" "${SYSCALLS_TO_COMPILE}" 

  if [ "$(which libtoolize)" != "" ]; then
    libtoolize && aclocal && automake --add-missing && autoconf
  else
    if [ "$(which glibtoolize)" != "" ]; then
      glibtoolize && aclocal && automake --add-missing && autoconf
    else
      echo "missing (g)libtoolize"
      exit 1
    fi
  fi
fi

