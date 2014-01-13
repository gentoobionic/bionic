#include <stdio.h>
#include <mntent.h>

/*****************/

#include <string.h>

#include "set_errno.h"

static inline char *find_next_optp(char *optp) {
	char *o;
	for( o = optp; o && *o && *o != ','; o++);
	if ( o && *o && *o == ',')
		o++;
	return o;
}

char *hasmntopt(const struct mntent *mnt, const char *opt) {
	char *r = NULL;

	if ( !(mnt && opt) ) {
		WOULD_SET_ERRNO(EINVAL);
		goto out;
	}

	for( r = mnt->mnt_opts;
		r && strncmp(r,opt,strlen(opt));
		r = find_next_optp(r) );

out:
	return r;
}
