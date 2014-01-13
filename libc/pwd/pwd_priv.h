#ifndef PWD_PRIV_H_
#define PWD_PRIV_H_

#define MWS "[ \t]*"

#define NATDIGIT "[1-9]"
#define NATPDIGIT "[0-9]"
#define NATP  "0|" NATDIGIT NATPDIGIT "*"

/* FIXME: Use posix NAME_MAX instead of a hardcoded 255. Keep in mind as
 * well, that the PATH_MAX is 4096, which is much less than the typical
 * buffer size for reading entries, in any case.
 * #include <linux/limits.h>
 */
#define PW_PATHELEM "[^/: \t]{1,255}"
#define PW_DIRPATH "/((" PW_PATHELEM "/)*" PW_PATHELEM ")?"
#define PW_FILEPATH "/(" PW_PATHELEM "/)*" PW_PATHELEM

#define PW_NAME_PAT   "[a-z_-]+"
#define PW_PASSWD_PAT "[*]|x"
#define PW_UID_PAT    NATP
#define PW_GID_PAT    NATP
#define PW_GECOS_PAT  "[^:]*"
#define PW_DIR_PAT    PW_DIRPATH
#define PW_SHELL_PAT  PW_FILEPATH

// FIXME: use posix constraints on user names
#define PWDLINE \
	"^" \
	"(" PW_NAME_PAT "):" \
	"(" PW_PASSWD_PAT "):" \
	"(" PW_UID_PAT "):" \
	"(" PW_GID_PAT "):" \
	"(" PW_GECOS_PAT "):" \
	"(" PW_DIR_PAT "):" \
	"(" PW_SHELL_PAT ")" \
	MWS \
	"$"

enum {
	PW_NAME = 0,
	PW_PASSWD,
	PW_UID,
	PW_GID,
	PW_GECOS,
	PW_DIR,
	PW_SHELL,
};

#define PW_NMATCH 11
#define PW_MATCH_INDECES \
	{ \
		[PW_NAME]   = 1, \
		[PW_PASSWD] = 2, \
		[PW_UID]    = 3, \
		[PW_GID]    = 4, \
		[PW_GECOS]  = 5, \
		[PW_DIR]    = 6, \
		[PW_SHELL]  = 9, \
	}

#ifndef _PATH_PASSWD
#define _PATH_PASSWD "/etc/passwd"
#endif

#endif /* PWD_PRIV_H_ */

