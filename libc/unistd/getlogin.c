#include <unistd.h>

char *getlogin(void);

/***************/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <pwd.h>

#include "set_errno.h"

char* getlogin(void) {
	char *n = NULL;
	int r, fd;
	struct stat stat;
	uid_t uid;
	struct passwd *p;

	/* XXX: Do not use getuid(), because that uid might be different than
	 * that of the controlling terminal, which might not even exist. */

	r = open("/dev/tty",O_RDONLY);
	if ( r == -1 )
		goto out;
	fd = r;

	r = fstat(fd,&stat);
	if ( r == -1 )
		goto closefd;

	uid = stat.st_uid;

	p = getpwuid(uid);
	if ( !p )
		goto closefd;

	n = p->pw_name;
	SET_ERRNO(0);

closefd:
	close(fd);

out:
	return n;
}
