#include <stdio.h>

ssize_t getdelim(char **lineptr, size_t *n, int delim, FILE *stream);

/**********************/

#include <stdlib.h> // malloc, free
#include <stdbool.h>
#include <string.h> // memset,memcpy
#define NDEBUG
#include <assert.h>

#include "set_errno.h"
#include "branch_prediction.h"

static inline int has_delim_at(char *s, unsigned n, int delim) {
	unsigned i;
	for(i=0; i<n; i++)
		if ( s[i] == delim )
			return i;
	return -1;
}

ssize_t getdelim(char **lineptr, size_t *n, int delim, FILE *stream) {

	const size_t sz = 120; // default chunk size
	char *buf, *p;
	int read_size, buf_size, buf_offset, delim_offset, file_offset_orig, file_offset;

	ssize_t r = -1;

	if ( unlikely( !(lineptr && n && stream) ||
		 fileno(stream) == -1 ||
		 (file_offset_orig = file_offset = ftell(stream)) == -1) ) {
		errno = EINVAL;
		goto out;
	}

	buf = malloc(sz);
	if ( !buf ) {
		WOULD_SET_ERRNO(ENOMEM);
		SHOULD_SET_ERRNO(EINVAL);
		goto out;
	}
	buf_size = sz;

	for(buf_offset = 0;; buf_offset += read_size) {
		read_size = fread(&buf[buf_offset],1,buf_size-buf_offset-1,stream);
		if ( read_size == 0 ) {
			if ( feof(stream) ) {
				if ( !buf_offset )
					goto free_buffer;
				else
					goto copy_buffer;
			} else {
				// FIXME: handle e.g. network streams or streams that
				// have an underlying file descriptor with O_ASYNC
				assert(1==0);
			}
		}
		delim_offset = has_delim_at(
						&buf[buf_offset],buf_size-buf_offset,delim);
		if ( delim_offset >= 0 ) {
			buf_offset += delim_offset;
			fseek(stream,file_offset + buf_offset + 1, SEEK_SET);
			SET_ERRNO(0);
			goto copy_buffer;
		}
		if ( buf_size-buf_offset-read_size >= sz/2 ) {
			p = realloc(buf,buf_size + sz);
			if ( !p ) {
				WOULD_SET_ERRNO(ENOMEM);
				SHOULD_SET_ERRNO(EINVAL);
				goto rewind_stream;
			}
			buf = p;
			buf_size += sz;
		}
	}

copy_buffer:
	*n = buf_size;
	if ( buf[buf_offset] == delim ) {
		r = buf_offset + 1;
		buf[buf_offset+1] = '\0';
	} else {
		r = buf_offset;
		buf[buf_offset] = '\0';
	}
	if ( *lineptr ) {
		if ( *n != buf_size ) {
			p = realloc(*lineptr,buf_size);
			if ( !p ) {
				WOULD_SET_ERRNO(ENOMEM);
				SHOULD_SET_ERRNO(EINVAL);
				*n = 0;
				r = -1;
				goto rewind_stream;
			}
			*lineptr = p;
		}
		if ( buf[buf_offset] == delim ) {
			memcpy(*lineptr,buf,buf_offset+2);
		} else {
			memcpy(*lineptr,buf,buf_offset+1);
		}
		goto free_buffer;
	} else {
		*lineptr = buf;
		goto out;
	}

rewind_stream:
	fseek(stream,file_offset_orig,SEEK_SET);

free_buffer:
	if ( buf )
		free(buf);

out:
	return r;
}
