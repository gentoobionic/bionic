#include <netinet/ether.h>

int ether_line(const char *line, struct ether_addr *addr, char *hostname);

/****************/

#include "stub.h"

#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <regex.h>
#include <stdlib.h>

//#define NDEBUG
#ifdef NDEBUG
#include <assert.h>
#endif

#include "ether_priv.h"

#define NAT         "[1-9]"
#define NATP        "[0-9]"
#define DOT         "[.]"
#define COLON		"[:]"
#define WS          "[ \\t]"
#define HEX         "[0-9a-fA-F]"
#define ETHADDR     "(" HEX HEX COLON "){5}" HEX HEX
#define HEXDASH     "[0-9a-fA-F-]"
#define ALNUM       "[0-9a-zA-Z]"
#define LABEL1      ALNUM "{1,63}"
#define ALNUMDASH   "[0-9a-zA-Z-]"
#define LABEL2      ALNUM ALNUMDASH "{0,61}" ALNUM
#define LABEL		"(" LABEL1 "|" LABEL2 ")"
#define FQDN        LABEL "(" DOT LABEL ")+" DOT "?"
#define IP4         "(" NATP "{1,3}" DOT "){3}" NATP "{1,3}"

// FIXME: clean up IP6 regular expressions

#define IP6         "(" COLON COLON "1|(" HEX "{0,4}" COLON "){7}" HEX "{0,4})"
#define IP64        IP6 COLON IP4

/* A complete, valid, /etc/ethers line with group operators in place for
 * regexec. Keep in mind that the maximum length for the FQDN is 255
 * characters.
 */
#define ETHERSLINE  "^(" ETHADDR ")" WS "+(" LABEL "|" FQDN "|" IP4 ")" WS "*$"

static regex_t _etherspat;
static regex_t *etherspat = NULL;

static inline void init_etherspat(void) {
#ifdef NDEBUG
	int r;
	char err[256];
	char *regex;

	if ( !etherspat ) {

		//regex = ALNUMDASH "+";
		regex = ETHERSLINE;

		printf("using regex:\n%s\n", regex);

		r = regcomp(&_etherspat, regex, REG_EXTENDED);
		if ( r ) {
			regerror(r,etherspat,err,256);
			fprintf(stderr,"%s\n", err);
			assert(r==0);
		}
		etherspat = &_etherspat;
	}
#else
	if ( !etherspat ) {
		regcomp(&_etherspat, ETHERSLINE, 0);
		etherspat = &_etherspat;
	}
#endif
}

#ifndef ARRAY_SIZE
#define ARRAY_SIZE(x) (sizeof(x)/sizeof((x)[0]))
#endif

int ether_line(const char *line, struct ether_addr *addr, char *hostname) {
	regmatch_t match[9];
	int r = -1, i;
	char err[256];
	char *dup;
	int m[] = {1,3};

	BIONICSTUB();
	fprintf(stderr,"still need to implement IPV6 regex pattern matching\n");

//	if ( !(line && addr && hostname) )
//		goto out;

	init_etherspat();

	r = regexec(etherspat,line,ARRAY_SIZE(match),match,0);
	if ( r ) {
		regerror(r,etherspat,err,256);
		fprintf(stderr,"%s\n", err);
	} else {
		printf("matched:\n");
		for(i=0; i<ARRAY_SIZE(m); i++) {
			dup = strndup(&line[match[m[i]].rm_so],match[m[i]].rm_eo-match[m[i]].rm_so);
			printf("%s\n", dup);
			free(dup);
		}
	}

	return r;
}
