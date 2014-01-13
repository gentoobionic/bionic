#include <stdio.h>
#include <mntent.h>

/*****************/

#include "mntent_priv.h"

FILE *setmntent(const char *filename, const char *type) {
	FILE *fp;

	fp = fopen(filename,type);

/* XXX: the man pages say nothing about errno, but glibc's implementation
 * does not set it to zero on failure */
    return fp;
}
