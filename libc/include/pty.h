#ifndef PTY_H_
#define PTY_H_

#include <termios.h>

extern int openpty(int *amaster, int *aslave, char *name,
	const struct termios *termp, const struct winsize *winp);

#endif
