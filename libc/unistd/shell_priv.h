#ifndef SHELL_PRIV_H_
#define SHELL_PRIV_H_

#define MWS "[ \t]*"

/* FIXME: use NAME_MAX instead of 255, and figure out a way to get a numerical
 * define to slide into a string define */
#define PATHELEM "[^/ \t]{1,255}"
#define ABSPATH "/(" PATHELEM "/)*" PATHELEM

#define SH_SHELL_PAT ABSPATH

#define SHELLLINE \
	"^" \
	"(" SH_SHELL_PAT ")" \
	MWS \
	"$"

#ifndef _PATH_SHELLS
#define _PATH_SHELLS "/etc/shells"
#endif

#endif /* SHELL_PRIV_H_ */
