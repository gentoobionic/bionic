#include <sys/types.h>
#include <pwd.h>

struct passwd *getpwent(void);
void setpwent(void);
void endpwent(void);

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

#include "pwd_priv.h"
#include "set_errno.h"
#include "branch_prediction.h"

#ifndef ARRAY_SIZE
#define ARRAY_SIZE(x) (sizeof(x)/sizeof((x)[0]))
#endif

#define LINE_ALLOCATED 1024
static char line[LINE_ALLOCATED];

static FILE *pwd_fp = NULL;
static struct passwd __the_passwd;

struct passwd *getpwent(void) {

	struct passwd *p = NULL;
	int r;

	char *linep = NULL;
	size_t line_allocated = 0;
	ssize_t line_len;

	const char *pat = PWDLINE;
	const unsigned i[] = PW_MATCH_INDECES;
	static bool expr_initialized = false;
	static regex_t expr;
	regmatch_t match[PW_NMATCH];

	unsigned uid;
	unsigned gid;

	if ( unlikely(!pwd_fp) ) {
		pwd_fp = fopen(_PATH_PASSWD,"r");
		if ( unlikely(!pwd_fp) )
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
		line_len = getline(&linep,&line_allocated,pwd_fp);
		if ( unlikely(line_len == -1 || !linep ) )
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

		/* XXX: comments and blank lines are NOT allowed in /etc/passwd ! */

		r = regexec(&expr,linep,ARRAY_SIZE(match),match,0);
		if ( unlikely(r) )
			continue;

		break;
	}

	memset(line,'\0', LINE_ALLOCATED);
	memcpy(line,linep,line_len);
	free(linep);
	linep = NULL;

	for(r=0; r<line_len; r++)
		if ( line[r] == ':' )
			line[r] = '\0';

	r = sscanf(&line[match[i[PW_UID]].rm_so],"%u",&uid) +
		sscanf(&line[match[i[PW_GID]].rm_so],"%u",&gid);
	if ( unlikely(r != 2) )
		goto out;

	p = &__the_passwd;
	p->pw_name   = &line[match[i[PW_NAME]].rm_so];
	p->pw_passwd = &line[match[i[PW_PASSWD]].rm_so];
	p->pw_uid    = uid;
	p->pw_gid    = gid;
	p->pw_gecos  = &line[match[i[PW_GECOS]].rm_so];
	p->pw_dir    = &line[match[i[PW_DIR]].rm_so];
	p->pw_shell  = &line[match[i[PW_SHELL]].rm_so];

out:
	if ( linep ) {
		free(linep);
		linep = NULL;
	}

	return p;
}

// according to the man pages, these functions are not supposed to set errno
void setpwent(void) {
	int e = errno;
	if (pwd_fp)
		fseek(pwd_fp,0,SEEK_SET);
	errno = e;
}
void endpwent(void) {
	int e = errno;
	if (pwd_fp) {
		fclose(pwd_fp);
		pwd_fp = NULL;
	}
	errno = e;
}
