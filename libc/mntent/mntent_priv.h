#ifndef MNTENT_PRIV_H_
#define MNTENT_PRIV_H_

#define MWS "[ \t]*"
#define SWS "[ \t]+"
#define PSEUDOFS "[a-z_-]+"

/* FIXME: use NAME_MAX instead of 255, and figure out a way to get a numerical
 * define to slide into a string define */
#define PATHELEM "[^/ \t]{1,255}"
#define ABSPATH "/((" PATHELEM "/)*" PATHELEM ")?"

#define NAT  "([1-9][0-9]*)"
#define NATP "0|" NAT ""

#define FS_SPEC_PAT    PSEUDOFS "|" ABSPATH
#define FS_FILE_PAT    ABSPATH
#define FS_VFSTYPE_PAT "[a-zA-Z0-9._-]+"
#define MNTOP          "[a-zA-Z0-9._=-]+"
#define	FS_MNTOPS_PAT  MNTOP "(," MNTOP ")*"
#define FS_FREQ_PAT    NATP
#define FS_PASSNO_PAT  NATP

#define FSTABPAT \
	"^" \
	"(" FS_SPEC_PAT ")" SWS \
	"(" FS_FILE_PAT ")" SWS \
	"(" FS_VFSTYPE_PAT ")" SWS \
	"(" FS_MNTOPS_PAT ")" SWS \
	"(" FS_FREQ_PAT ")" SWS \
	"(" FS_PASSNO_PAT ")" MWS \
	"$"

#define _PATH_FSTAB "/etc/fstab"
#define _PATH_PROC_MOUNTS "/proc/mounts"

#define NMATCH 14
#define MATCHINDECES {1,4,7,8,10,12}

enum {
	FS_SPEC = 0,
	FS_FILE,
	FS_VFSTYPE,
	FS_MNTOPS,
	FS_FREQ,
	FS_PASSNO,
	FS_MAX,
};

#endif /* MNTENT_PRIV_H_ */
