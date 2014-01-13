#ifndef _HAVE_SYS_SHM_H_
#define _HAVE_SYS_SHM_H_

 #include <linux/shm.h>
 
__BEGIN_DECLS

extern void *shmat(int, const void *, int);
extern int   shmctl(int, int, struct shmid_ds *);
extern int   shmdt(const void *);
extern int   shmget(key_t, size_t, int);

__END_DECLS

#endif /* _HAVE_SYS_SHM_H_ */

