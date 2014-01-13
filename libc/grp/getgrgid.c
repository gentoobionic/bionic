#include <sys/types.h>
#include <grp.h>

struct group *getgrgid(gid_t gid);

/*********************************/

#include <stddef.h>

struct group *getgrgid(gid_t gid) {
	struct group *g = NULL;

	setgrent();
	for( g = getgrent(); g && g->gr_gid != gid; g = getgrent());
	endgrent();

	return g;
}
