#include <stdio.h>
#include <mntent.h>

int endmntent(FILE *fp);

/***************************/

#include "set_errno.h"

int endmntent(FILE *fp) {
    if ( fp )
        fclose(fp);
    SHOULD_SET_ERRNO(0);
/* XXX: the man pages say nothing about errno, but glibc's implementation
 * does not set it to zero on failure */
    return 1;
}
