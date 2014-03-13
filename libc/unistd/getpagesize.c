#include <unistd.h>

extern unsigned int __page_size;

// FIXME: page size should be dynamically discovered from the kernel
int getpagesize() {
  return __page_size;
}

