#include <sys/types.h>
#include <pwd.h>

struct passwd *getpwuid(uid_t uid);

/****************/

#include <stddef.h> // NULL

struct passwd *getpwuid(uid_t uid) {
	struct passwd *p = NULL;

	setpwent();
	do {
		p = getpwent();
	} while(p && p->pw_uid != uid);
	endpwent();

	return p;
}
