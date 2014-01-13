#include <stdio.h>
#include <mntent.h>

/*******************************/

#include <stdlib.h>
#include <stdbool.h>
#include <regex.h>
#include <ctype.h>
#include <string.h>
#ifndef NDEBUG
#define NDEBUG
#endif
#include <assert.h>

#include "set_errno.h"
#include "mntent_priv.h"
#include "branch_prediction.h"

#ifndef ARRAY_SIZE
#define ARRAY_SIZE(x) (sizeof(x)/sizeof((x)[0]))
#endif

#define LINE_ALLOC 1024
static char line[LINE_ALLOC];

static struct mntent __the_mntent;

// empty line or comment line
static bool eorc(const char *line, const size_t len) {
	char *o;
	for(o=(char *)line; (o-line) < len && isblank(*o); o++);
	return (o-line) == len || *o == '#';
}

struct mntent *getmntent(FILE *fp) {
	const char *pat = FSTABPAT;
	struct mntent *ent = NULL;
	char *linep = NULL;
	ssize_t line_len;
	size_t line_alloc = LINE_ALLOC;
	static bool expr_initialized = false;
	static regex_t expr;
	regmatch_t match[NMATCH];
	int r, j;
	const int i[] = MATCHINDECES;

	if ( !expr_initialized ) {
		r = regcomp(&expr, pat, REG_EXTENDED | REG_NEWLINE);
		assert(!r);
		if ( unlikely(r) ) {
			WOULD_SET_ERRNO(EINVAL);
			goto out;
		}
		expr_initialized = true;
	}

	for(;;) {
		line_len = getline(&linep,&line_alloc,fp);

		if ( unlikely(line_len == -1) )
			goto out;

		if ( unlikely( line_len >= LINE_ALLOC || line_len <= 1 ) ) {
			SET_ERRNO(ENOBUFS);
			goto out;
		}

		if ( likely(linep[line_len-1] == '\n') ) {
			linep[line_len-1] = '\0';
			line_len--;
		}

		if ( eorc(linep,line_len) )
			continue;

		// try to match the pattern, skip lines if there is no match
		r = regexec(&expr,linep,NMATCH,match,0);
		if ( unlikely(r) )
			continue;

		memset(line,'\0',LINE_ALLOC);
		memcpy(line,linep,line_len);
		free(linep);
		linep = NULL;

		for(j=0; j<ARRAY_SIZE(i); j++)
			line[match[i[j]].rm_eo] = '\0';

		ent = &__the_mntent;

		ent->mnt_fsname = &line[match[i[FS_SPEC]].rm_so];
		ent->mnt_dir = &line[match[i[FS_FILE]].rm_so];
		ent->mnt_type = &line[match[i[FS_VFSTYPE]].rm_so];
		ent->mnt_opts = &line[match[i[FS_MNTOPS]].rm_so];

		r =
			sscanf(&line[match[i[FS_FREQ]].rm_so],"%u",&ent->mnt_freq) +
			sscanf(&line[match[i[FS_PASSNO]].rm_so],"%u",&ent->mnt_passno);
		if ( unlikely(r != 2) ) {
			ent = NULL;
			WOULD_SET_ERRNO(EINVAL);
			goto out;
		}

		break;
	}

out:
	if ( linep ) {
		free(linep);
		linep = NULL;
	}
	/* XXX: the man pages say nothing about errno, but glibc's implementation
	 * does not set it to zero on failure */
	return ent;
}
