#include <netinet/ether.h>

#include "set_errno.h"

int ether_hostton(const char *hostname, struct ether_addr *addr);

/**************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ether_priv.h"
#include "stub.h"

static inline size_t min( size_t a, size_t b ) {
	return a <= b ? a : b;
}

static inline void reset_hostname(char *hn) {
	int i;
	for(i=0; i<POSIX_HOST_NAME_MAX; i++) {
		hn[i] = ' ';
	}
	hn[POSIX_HOST_NAME_MAX] = '\0';
}

int ether_hostton(const char *hostname, struct ether_addr *addr) {

	int r = -1, invalid_ether_line;
	char *hnt;
	char *line = NULL;
	size_t buflen = 0;
	ssize_t linelen;
	struct ether_addr taddr = {};

	FILE *ethers = NULL;

	BIONICSTUB();
	fprintf(stderr,"this is still waiting for ether_line.c\n");

	if ( !( hostname && addr ) )
		goto out;

	ethers = fopen(ETHERS_FILENAME,"r");
	if ( !ethers ) {
		errno = 0;
		goto out;
	}

	hnt = malloc(POSIX_HOST_NAME_MAX + 1);
	if ( !hnt ) {
		goto close_ethers;
	}

	for(;;) {
		reset_hostname(hnt);
		if ( line ) {
			free(line);
			line = NULL;
		}

		linelen = getline(&line,&buflen,ethers);

		// end of file reached
		if ( linelen == -1 )
			break;

		invalid_ether_line =
			ether_line(line,&taddr,hnt);

		if ( invalid_ether_line )
			continue;

		if ( strncmp(hostname,hnt,
				min(strlen(hnt),strlen(hostname))) == 0 ) {
			memcpy(addr,&taddr,sizeof(struct ether_addr));
			r = 0;
			break;
		}
	}

	if ( line ) {
		free(line);
		line = NULL;
	}

	if ( hnt ) {
		free(hnt);
		hnt = NULL;
	}

close_ethers:
	if ( ethers ) {
		fclose(ethers);
		ethers = NULL;
	}

out:

	SHOULD_CLEAR_ERRNO();

    return r;
}
