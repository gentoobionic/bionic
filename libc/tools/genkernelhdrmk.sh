#!/bin/sh

usage() {
  echo "usage: $0 [path/to/bionic] [x86|arm|..]]"
}

if [ $# -ne 2 ]; then
  usage
  exit 1
fi

ARCH=${2}
TOP_SRCDIR=${1}

if [ ! -d ${TOP_SRCDIR}/linker  ]; then
  echo "could not find 'linker' directory. is '${TOP_SRCDIR}' really bionic?"
  usage
  exit 1
fi

KERNEL_INCDIRS="libc/kernel/common libc/kernel/arch-${ARCH}"

echo "if KERNEL_HEADERS"

for kinc in $KERNEL_INCDIRS; do
  cd ${TOP_SRCDIR}
  cd ${kinc}
  DIRS="$(for h in $(find * -name '*.h' -type f); do dirname ${h}; done | grep -v "^\." | sort -u)"
  for d in $DIRS; do
    dirvar="$(echo $d | sed -e 's|[/_-]||g')"
    echo -e "include${dirvar}dir = \$(includedir)/${d}"
    HDRS="$(find ${d} -name '*.h' -type f)"
    echo -e "include${dirvar}_HEADERS = \\"
    echo -e "\t\$(addprefix \$(top_srcdir)/${kinc}/, \\"
    for h in $HDRS; do
      echo -e "\t\t${h} \\"
    done
    echo -e "\t)"
  done
done

echo "endif"
