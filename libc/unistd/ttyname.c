#include <unistd.h>

char *ttyname(int fd);

/***************/

#include <linux/limits.h> // NAME_MAX

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <pwd.h>

#include <stdio.h>

#include "branch_prediction.h"
#include "set_errno.h"

// it's unlikely that we'll ever need to switch this to PATH_MAX
static char ttypathname[NAME_MAX];

#ifndef min
#define min(a,b) ((a)<=(b) ? (a) : (b))
#endif

char *ttyname(int fd) {
	char *n = NULL;
	int r;
	pid_t pid;
	int procfd;
	ssize_t len;

	if ( !isatty(fd) )
		goto out;

	pid = getpid();

	// XXX: very linux-specific
	r = snprintf(ttypathname,sizeof(ttypathname),"/proc/%u/fd/%u",pid,fd);
	if ( unlikely(r < 0) )
		goto out;

	procfd = open(ttypathname,O_RDONLY);
	if ( procfd == -1 )
		goto out;

	len = readlink(ttypathname,ttypathname,sizeof(ttypathname));
	if ( unlikely(r == -1) )
		goto closeprocfd;

	ttypathname[min(sizeof(ttypathname),len)] = '\0';

	n = ttypathname;
	SET_ERRNO(0);

closeprocfd:
	close(procfd);

out:
	return n;
}
