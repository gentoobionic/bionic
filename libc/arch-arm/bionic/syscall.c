#include <errno.h>

extern void __syscall();

int syscall( int nr, int arg0, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6 );
int syscall( int nr, int arg0, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6 ) {

	register int r0 __asm__( "r0" );
	register int r1 __asm__( "r1" );
	register int r2 __asm__( "r2" );
	register int r3 __asm__( "r3" );
	register int r4 __asm__( "r4" );
	register int r5 __asm__( "r5" );
	register int r6 __asm__( "r6" );

	r0 = nr;
	r1 = arg0;
	r2 = arg1;
	r3 = arg2;
	r4 = arg3;
	r5 = arg4;
	r6 = arg5;

	__syscall();

	if ( (unsigned)r0 > -4096UL ) {
		errno = -r0;
		r0 = -1;
	}
	return r0;
}
