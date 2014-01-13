#ifndef SHOULD_CLEAR_ERRNO_H_
#define SHOULD_CLEAR_ERRNO_H_

#include <errno.h>

/* Some functions call others that might set errno.
 * However, the functions themselves are not specified
 * to set errno on failure. Enabling this will make
 * those functions clear errno before returning,
 * regardless of the previous state of errno or any
 * failure on behalf of the function.
 */
#define BE_GOOD 1
#if BE_GOOD
#define SHOULD_SET_ERRNO(x) \
	{ errno = x; }
#define WOULD_SET_ERRNO(x) \
	do {} while(0)
#else
#define SHOULD_SET_ERRNO(x) \
	do {} while(0)
#define WOULD_SET_ERRNO(x) \
	{ errno = x; }
#endif
#undef BE_GOOD

#define SET_ERRNO(x) \
	{ \
		WOULD_SET_ERRNO(x); \
		SHOULD_SET_ERRNO(x); \
	}
#define SHOULD_CLEAR_ERRNO() SHOULD_SET_ERRNO(0)

#endif /* SHOULD_CLEAR_ERRNO_H_ */
