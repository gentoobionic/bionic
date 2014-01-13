#include <shadow.h>

void setspent();

/***************************/

#include <stddef.h>

#include "stub.h"
#include "set_errno.h"

void setspent() {
	BIONICSTUB();
	SET_ERRNO(ENOSYS);
}
