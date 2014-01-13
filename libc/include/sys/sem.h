#ifndef _HAVE_SYS_SEM_H_
#define _HAVE_SYS_SEM_H_

#include <linux/sem.h>

__BEGIN_DECLS

extern int semctl(int semid, int semnum, int cmd, ...);
extern int semget(key_t key, int nsems, int semflg);
extern int semop(int semid, struct sembuf *sops, size_t nsops);

__END_DECLS

#endif /* _HAVE_SYS_SEM_H_ */

