#include <shadow.h>

int ulckpwdf();

/***************************/

#include <stddef.h>

#include "stub.h"
#include "set_errno.h"

int ulckpwdf() {
	BIONICSTUB();
	SET_ERRNO(ENOSYS);
	return -1;
}
