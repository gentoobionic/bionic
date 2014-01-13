#include <termios.h>
#include <unistd.h>

int tcdrain(int fd);

/***************************/

#include <sys/ioctl.h>

int tcdrain(int fd) {
	return ioctl(fd,TCSBRK,1);
}
