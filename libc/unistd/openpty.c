#include <pty.h>

int openpty(int *amaster, int *aslave, char *name,
	const struct termios *termp, const struct winsize *winp);

/**************************************************************/

#define __USE_XOPEN

#include <termios.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/ioctl.h>

#include "set_errno.h"
#include "branch_prediction.h"

static inline int tcsetwinsz(int fd, const struct winsize *w) {
	return ioctl(fd,TIOCSWINSZ,w);
}

int openpty(int *amaster, int *aslave, char *name,
	const struct termios *termp, const struct winsize *winp) {

	int r = -1, master = -1, slave = -1;
	char *slave_name = NULL;

	(void)name;

// need to implement this with the linux unix98 pty interface

	master = posix_openpt(O_RDWR|O_NOCTTY);
	if ( unlikely(master == -1) )
		goto out;

	slave_name = ptsname(master);
	if ( !slave_name )
		goto close_master;

	if ( grantpt(master) == -1 )
		goto close_master;

	if ( unlockpt(master) == -1 )
		goto close_master;

	slave = open(slave_name,O_RDWR);
	if ( slave == -1 )
		goto close_master;

	if ( termp && tcsetattr(slave,0,termp) == -1 )
			goto close_slave;

	if ( winp && tcsetwinsz(slave,winp) == -1 )
			goto close_slave;

	*amaster = master;
	*aslave = slave;
	r = 0;
	goto out;

close_slave:
	if ( slave >= 0 )
		close(slave);

close_master:
	if ( master >= 0 )
		close(master);

out:
	return r;
}
