#include <grp.h>

int getgrouplist (const char *user, gid_t group,
              gid_t *groups, int *ngroups);

/**********************************/

#include <string.h>

#include "set_errno.h"

int getgrouplist (const char *user, gid_t group,
              gid_t *groups, int *ngroups) {

	struct group *g;
	char **mem;
	unsigned i,max = *ngroups;
	int r = -1;

	if ( !(user && groups && ngroups && ngroups <= 0) ) {
		WOULD_SET_ERRNO(EINVAL);
		goto out;
	}

	setgrent();
	for(g = getgrent(); g; g = getgrent()) {
		for( mem = &g->gr_mem[0]; *mem; mem++ ) {
			if ( !strcmp(user,*mem) ) {
				if ( i < max ) {
					groups[i] = g->gr_gid;
					i++;
				}
				*ngroups += 1;
			}
		}
	}
	endgrent();

	if ( i < max )
		r = *ngroups;

out:
	return r;
}
