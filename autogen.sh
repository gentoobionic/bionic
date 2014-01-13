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
  for e in la lo lai o so in m4 stamp class inc; do
    rm -f $(find . -name "*.${e}" -type f)
  done
  for e in Makefile depcomp INSTALL config.guess config.sub config.log config.status configure install-sh ltmain.sh missing libtool; do
    rm -f $(find . -name "${e}" -type f -o -type l)
  done
  for e in autom4te.cache .libs .deps; do
    rm -Rf $(find . -name "${e}" -type d)
  done
else
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

