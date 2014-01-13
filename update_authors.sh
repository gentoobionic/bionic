#!/bin/sh

PROJ=bionic

if [ "$(grep "AC_INIT(${PROJ}" configure.ac)" = "" ]; then
  echo "autogen.sh must be run in PWD of ${PROJ} source"
  exit 1
fi
grep "^[0-9]" ChangeLog | awk '{split($0,a,"\t"); printf("%s, %s, %s\n", a[1] ,a[2], a[3]);}' | sort | sort -u -k 3.2 > AUTHORS
