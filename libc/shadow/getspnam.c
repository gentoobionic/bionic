#include <shadow.h>

struct spwd *getspnam(char *name);

/***************************/

#include <stddef.h>

#include "stub.h"
#include "set_errno.h"

struct spwd *getspnam(char *name) {
	BIONICSTUB();
	SET_ERRNO(ENOSYS);
	return NULL;
}
