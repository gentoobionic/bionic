#ifndef _SHADOW_H
#define _SHADOW_H       1

#define __need_FILE
#include <stdio.h>
#define __need_size_t
#include <stddef.h>

__BEGIN_DECLS

struct spwd;

struct spwd *getspent();
struct spwd *getspnam(char *name);
void setspent();
void endspent();
struct spwd *fgetspent(FILE *fp);
struct spwd *sgetspent(char *cp);
int putspent(struct spwd *p, FILE *fp);
int lckpwdf();
int ulckpwdf();

struct spwd {
  char *            sp_namp;
  char *            sp_pwdp;
  long int          sp_lstchg;
  long int          sp_min;
  long int          sp_max;
  long int          sp_warn;
  long int          sp_inact;
  long int          sp_expire;
  unsigned long int sp_flag;
};

__END_DECLS

#endif /* _SHADOW_H */
