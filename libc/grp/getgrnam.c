#include <sys/types.h>
#include <grp.h>

struct group *getgrnam(const char *name);

/*********************************/

#include <stddef.h>
#include <string.h>

struct group *getgrnam(const char *name) {
	struct group *g = NULL;

	setgrent();
	for( g = getgrent(); g && !strcmp(g->gr_name,name); g = getgrent());
	endgrent();

	return g;
}
