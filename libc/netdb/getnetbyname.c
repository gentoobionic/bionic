#include <netdb.h>

#include <stddef.h> // NULL

#include "stub.h"

static struct netent __the_netent = {};

struct netent* getnetbyname(const char *name) {
	struct netent *nep = NULL;
    BIONICSTUB();
    return nep;
}
