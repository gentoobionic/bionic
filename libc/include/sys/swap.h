#ifndef _SYS_SWAP_H_
#define _SYS_SWAP_H_

#include <linux/swap.h>

__BEGIN_DECLS

extern int swapon(const char *path, int swapflags);
extern int swapoff(const char *path);

__END_DECLS

#endif /* _SYS_SWAP_H_ */
