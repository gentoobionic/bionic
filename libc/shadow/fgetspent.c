#include <shadow.h>

struct spwd *fgetspent(FILE *fp);

/***************************/

#include <stddef.h>

#include "stub.h"
#include "set_errno.h"

struct spwd *fgetspent(FILE *fp) {
	BIONICSTUB();
	SET_ERRNO(ENOSYS);
	return NULL;
}
