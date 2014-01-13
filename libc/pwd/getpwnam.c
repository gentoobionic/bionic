#include <sys/types.h>
#include <pwd.h>

struct passwd *getpwnam(const char *name);

/****************/

#include <string.h> // strcmp
#include <stddef.h> // NULL

struct passwd *getpwnam(const char *name) {
	struct passwd *p = NULL;

	setpwent();
	do {
		p = getpwent();
	} while(p && strcmp(name,p->pw_name));
	endpwent();

	return p;
}
