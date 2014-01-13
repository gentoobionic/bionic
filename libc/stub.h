#ifndef BIONIC_STUB_H_
#define BIONIC_STUB_H_

#ifdef BIONIC_STUB_WARNINGS
#include <stdio.h>
#include <unistd.h>
#define BIONICSTUB() \
	fprintf(stderr,"FIX ME! implement %s()\n", __FUNCTION__)
#else
#define BIONICSTUB()
#endif /* BIONIC_STUB_WARNINGS */

#endif /* BIONIC_STUB_H_ */
