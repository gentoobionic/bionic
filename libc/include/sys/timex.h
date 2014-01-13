#ifndef _SYS_TIMEX_H_
#define _SYS_TIMEX_H_

#include <linux/timex.h>

__BEGIN_DECLS

extern int adjtimex(struct timex *buf);

__END_DECLS

#endif /* _SYS_TIMEX_H_ */
