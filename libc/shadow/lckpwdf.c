#include <shadow.h>

int lckpwdf();

/***************************/

#include <stddef.h>

#include "stub.h"
#include "set_errno.h"

int lckpwdf() {
	BIONICSTUB();
	SET_ERRNO(ENOSYS);
	return 0;
}
