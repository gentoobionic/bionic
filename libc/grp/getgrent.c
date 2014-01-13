#include <sys/types.h>
#include <grp.h>

struct group *getgrent(void);
void setgrent(void);
void endgrent(void);

/******************************/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <errno.h>
#include <regex.h>
#include <stdlib.h>
#ifndef NDEBUG
// enabling this will make any program die if 'pat' does not compile
//#define NDEBUG
#endif
#include <assert.h>

#include "grp_priv.h"
#include "set_errno.h"
#include "branch_prediction.h"

#ifndef ARRAY_SIZE
#define ARRAY_SIZE(x) (sizeof(x)/sizeof((x)[0]))
#endif

#define LINE_ALLOCATED 1024
static char line[LINE_ALLOCATED];

static FILE *__grp_fp;
static struct group __the_group;

/* FIXME: this is extremely superficial, since posix systems could theoretically
 * support tens of thousands of users in the group 'users', but it helps in that
 * it is a small number of pointers that can be allocated statically */
#define GR_MAX_MEMBERS 63
static char *mem[GR_MAX_MEMBERS+1];

static inline bool parse_gr_mem(char *m,size_t l) {
	const char d = ',';
	bool r = false;
	char *o, last;
	unsigned i;

	for(i=0; i<GR_MAX_MEMBERS+1; mem[i] = NULL, i++);

	for( last =-1, o=m, i=0; o && (o-m) < l && i < (GR_MAX_MEMBERS+1); last = *o, o++ ) {
		if ( last == d ) {
			mem[i] = o;
			*(o-1) = '\0';
		}
	}
	if ( i >= (GR_MAX_MEMBERS+1) && (o-m) != l )
		r = false;

	return r;
}

struct group *getgrent(void) {

	struct group *g = NULL;
	int r;

	char *linep = NULL;
	size_t line_allocated = LINE_ALLOCATED;
	ssize_t line_len;

	const char *pat = GRPLINE;
	const unsigned i[] = GR_MATCH_INDECES;
	static bool expr_initialized = false;
	static regex_t expr;
	regmatch_t match[GR_NMATCH];

	FILE *fp = __grp_fp;

	unsigned gid;

	if ( unlikely(!fp) ) {
		fp = fopen(_PATH_PASSWD,"r");
		if ( unlikely(!fp) )
			goto out;
	}

	if ( !expr_initialized ) {
		r = regcomp(&expr,pat,REG_EXTENDED);
		assert(r != -1);
		if ( unlikely(r == -1) ) {
			SHOULD_SET_ERRNO(EIO);
			goto out;
		}
		expr_initialized = true;
	}

	for(;;) {
		line_len = getline(&linep,&line_allocated,fp);

		if ( unlikely(line_len == -1) )
			goto out;

		if ( line_len >= LINE_ALLOCATED ) {
			SET_ERRNO(ENOBUFS);
			goto out;
		}

		if ( line_len <= 1 )
			continue;

		if (linep[line_len-1] == '\n') {
			linep[line_len-1] = '\0';
			line_len--;
		}

		/* XXX: comments and blank lines are NOT allowed in /etc/group ! */

		r = regexec(&expr,linep,ARRAY_SIZE(match),match,0);
		if ( unlikely(r) )
			continue;
	}

	memset(line,'\0',LINE_ALLOCATED);
	memcpy(line,linep,line_len);
	free(linep);
	linep = NULL;

	for(r=0; r<line_len; r++)
		if ( line[r] == ':' )
			line[r] = '\0';

	r = sscanf(&line[match[i[GR_GID]].rm_so],"%u",&gid);
	if ( unlikely(r != 1) )
		goto out;

	if ( !parse_gr_mem(&line[match[i[GR_MEM]].rm_so], match[i[GR_MEM]].rm_eo - match[i[GR_MEM]].rm_so) )
		goto out;

	g = &__the_group;
	g->gr_name   = &line[match[i[GR_NAME]].rm_so];
	g->gr_passwd = &line[match[i[GR_PASSWD]].rm_so];
	g->gr_gid    = gid;

out:
	if ( linep ) {
		free(linep);
		linep = NULL;
	}
	return g;
}

// according to the man pages, these functions are not supposed to set errno
void setgrent(void) {
	int e = errno;
	if (__grp_fp)
		fseek(__grp_fp,0,SEEK_SET);
	errno = e;
}
void endgrent(void) {
	int e = errno;
	if (__grp_fp) {
		fclose(__grp_fp);
		__grp_fp = NULL;
	}
	errno = e;
}
