#ifndef	_SYS_TIMERFD_H
#define	_SYS_TIMERFD_H	1

#include <time.h>

enum
  {
    TFD_CLOEXEC = 02000000,
#define TFD_CLOEXEC TFD_CLOEXEC
    TFD_NONBLOCK = 04000
#define TFD_NONBLOCK TFD_NONBLOCK
  };

enum
  {
    TFD_TIMER_ABSTIME = 0x1
#define TFD_TIMER_ABSTIME TFD_TIMER_ABSTIME
  };


__BEGIN_DECLS

extern int timerfd_create  (int clock_id, int flags);
extern int timerfd_settime (int fd, int flags, const struct itimerspec *new_value, struct itimerspec *old_value);
extern int timerfd_gettime (int fd, struct itimerspec *curr_value);

__END_DECLS

#endif
