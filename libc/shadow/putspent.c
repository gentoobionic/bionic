#include <shadow.h>

int putspent (struct spwd *p, FILE *fp);

/***************************/
#include <stddef.h>

#include "stub.h"
#include "set_errno.h"

int putspent (struct spwd *p, FILE *fp) {
	BIONICSTUB();
	SET_ERRNO(ENOSYS);
	return -1;
}
