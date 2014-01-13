#include <shadow.h>

void endspent();

/***************************/

#include <stddef.h>

#include "stub.h"
#include "set_errno.h"

void endspent() {
	BIONICSTUB();
	SET_ERRNO(ENOSYS);
}
