#include <machine/asm.h>
#include <sys/linux-syscalls.h>

/*
 * int  __pthread_clone(int (*fn)(void*), void *tls, int flags,
 *                      void *arg);
 */
ENTRY(__pthread_clone)
		PIC_PROLOGUE
        # save tls
        movl    %ecx, %ebx
        # 16-byte alignment on child stack
        andl    $~15, %ecx

        # insert arguments onto the child stack
        movl    12(%esp), %eax
        movl    %eax, -16(%ecx)
        movl    24(%esp), %eax
        movl    %eax, -12(%ecx)
        movl    %ebx, -8(%ecx)

        subl    $16, %ecx
        movl    20(%esp), %ebx
        movl    $__NR_clone, %eax
        int     $0x80
        test    %eax, %eax
        jns     1f

        # an error occured, set errno and return -1
        negl    %eax
        call    PIC_PLT(__set_errno)
        orl     $-1, %eax
        jmp     2f

1:
        jnz     2f

        # we're in the child thread now, call __thread_entry
        # with the appropriate arguments on the child stack
        # we already placed most of them
        call    PIC_PLT(__thread_entry)
        hlt

2:
        popl    %ecx
		PIC_EPILOGUE
        ret
END(__pthread_clone)

/* XXX: TODO: Add __bionic_clone here
 *            See bionic/bionic_clone.c and arch-arm/bionic/clone.S
 *            for more details...
 */
