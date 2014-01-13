#include <utmp.h>

#include <stddef.h> // NULL

#include "stub.h"

struct utmp __the_utmp = {};

struct utmp *getutid(struct utmp *ut) {
	struct utmp *utmp = NULL;
	BIONICSTUB();
    return utmp;
}
