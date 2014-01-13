#include <shadow.h>

struct spwd *getspent();

/***************************/

#include <stddef.h>

#include "stub.h"
#include "set_errno.h"

struct spwd *getspent() {
	BIONICSTUB();
	SET_ERRNO(ENOSYS);
	return NULL;
}
