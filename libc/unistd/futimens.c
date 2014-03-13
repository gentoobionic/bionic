#include <sys/stat.h>

int futimens(int fd, const struct timespec times[2]) {
	return utimensat(fd,NULL,times,0);
}
