#include <shadow.h>

struct spwd *sgetspent(char *cp);

/***************************/

#include <stddef.h>

#include "stub.h"
#include "set_errno.h"

struct spwd *sgetspent(char *cp) {
	BIONICSTUB();
	SET_ERRNO(ENOSYS);
	return NULL;
}
