#ifndef GRP_PRIV_H
#define GRP_PRIV_H

#include "../pwd/pwd_priv.h"

#define MWS "[ \t]*"

#define NATDIGIT "[1-9]"
#define NATPDIGIT "[0-9]"
#define NATP  "0|" NATDIGIT NATPDIGIT "*"

#define GR_NAME_PAT "[a-z_-]+"
/* XXX: I've never even heard of a group password in actual use, but they're
 * all 'x' in most distros */
#define GR_PASSWD_PAT "x"
#define GR_GID_PAT NATP
// FIXME: find a reasonable max number for
#define GR_MEM_PAT PW_NAME_PAT "(," PW_NAME_PAT ")*"

// FIXME: use posix constraints on group names
#define GRPLINE \
	"^" \
	"(" GR_NAME_PAT "):" \
	"(" GR_PASSWD_PAT "):" \
	"(" GR_GID_PAT "):" \
	"(" GR_MEM_PAT "):" \
	MWS \
	"$"

enum {
	GR_NAME = 0,
	GR_PASSWD,
	GR_GID,
	GR_MEM,
};

#define GR_NMATCH 9
#define GR_MATCH_INDECES \
	{ \
		[GR_NAME]   = 1, \
		[GR_PASSWD] = 2, \
		[GR_GID]    = 3, \
		[GR_MEM]    = 4, \
	}

#ifndef _PATH_GROUP
#define _PATH_GROUP "/etc/group"
#endif

#endif  /* GRP_PRIV_H */
