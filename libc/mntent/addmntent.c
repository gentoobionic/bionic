#include <stdio.h>
#include <mntent.h>

int addmntent(FILE *fp, const struct mntent *mnt);

/*****************/

#include <stddef.h>
#include <sys/types.h>

#include <stdbool.h>
#include <string.h>
#include <regex.h>
#ifndef NDEBUG
#define NDEBUG
#endif
#include <assert.h>

#include <unistd.h>
#include <sys/types.h>

#include "mntent_priv.h"
#include "set_errno.h"
#include "branch_prediction.h"

#ifndef ARRAY_SIZE
#define ARRAY_SIZE(x) (sizeof(x)/sizeof((x)[0]))
#endif

// XXX: see FIXME
//#define BUFSZ 1024
//static char __buf[BUFSZ];

int addmntent(FILE *fp, const struct mntent *mnt) {
	int r = 1, r2, i, fd;

	const char *pat[] = {
		[FS_SPEC]    = "(" FS_SPEC_PAT ")",
		[FS_FILE]    = "(" FS_FILE_PAT ")",
		[FS_VFSTYPE] = "(" FS_VFSTYPE_PAT ")",
		[FS_MNTOPS]  = "(" FS_MNTOPS_PAT ")",
	};
	static bool expr_initialized[ARRAY_SIZE(pat)] = {};
	static regex_t expr[ARRAY_SIZE(pat)] = {};
	regmatch_t match[2];

	long o1;

	char *inp[] = {
		[FS_SPEC]    = (char *)offsetof(struct mntent,mnt_fsname),
		[FS_FILE]    = (char *)offsetof(struct mntent,mnt_dir),
		[FS_VFSTYPE] = (char *)offsetof(struct mntent,mnt_type),
		[FS_MNTOPS]  = (char *)offsetof(struct mntent,mnt_opts),
	};

	if ( unlikely(!mnt) ) {
		WOULD_SET_ERRNO(EINVAL);
		goto out;
	}

	fd = fileno(fp);
	if ( unlikely(fd == -1) )
		goto out;

	if ( mnt->mnt_passno < 0 || mnt->mnt_freq < 0 ) {
		WOULD_SET_ERRNO(EINVAL);
		goto out;
	}

	for(i=0; !expr_initialized[i] && i<ARRAY_SIZE(pat); i++) {
		r2 = regcomp(&expr[i],pat[i],REG_EXTENDED);
		assert(!r2);
		if ( unlikely(r2) ) {
			WOULD_SET_ERRNO(EINVAL);
			goto out;
		}
		expr_initialized[i] = true;
	}

	for(i=0; i<ARRAY_SIZE(pat); i++) {

		inp[i] = *((char **)((size_t)mnt + (size_t)inp[i]));

		r2 = regexec(&expr[i],inp[i],ARRAY_SIZE(match),match,0);
		if ( unlikely(r2) ) {
			WOULD_SET_ERRNO(EINVAL);
			goto out;
		}
	}

	r2 = fseek(fp,0,SEEK_END);
	if ( unlikely(r2 == -1) )
		goto out;

	o1 = ftell(fp);
	if ( unlikely(o1 == -1) )
		goto out;

/* FIXME: This is unsafe because the *printf functions do not guarantee that
 * all elements have been written, and only return the number of characters
 * written. A safer way to do this would be to print to a static buffer, and
 * then match the static buffer against the FSTAB regular expression.
 * Iff the buffer matches, then use fwrite(), verifying that strlen(buf) bytes
 * have been written to the output.
 */
	r2 = fprintf(fp,"%s\t%s\t%s\t%s\t%u %u\n",
		mnt->mnt_fsname, mnt->mnt_dir, mnt->mnt_type,
		mnt->mnt_opts, mnt->mnt_freq, mnt->mnt_passno);
	if ( r2 < 0 ) {
		ftruncate(fd,o1);
		goto out;
	}

	r = 0;

out:
	return r;
}

