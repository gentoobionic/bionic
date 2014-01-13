#ifndef BRANCH_PREDICTION_H_
#define BRANCH_PREDICTION_H_

#define HAVE_BRANCH_PREDICTION
#ifdef HAVE_BRANCH_PREDICTION
#ifdef __GNUC__
#define likely(x) __builtin_expect((x),1)
#define unlikely(x) __builtin_expect((x),0)
#else
// TODO: BSD-licensed implementations of these macros
#define likely(x) (x)
#define unlikely(x) (x)
#endif

#else
#define likely(x) (x)
#define unlikely(x) (x)
#endif /* HAVE_BRANCH_PREDICTION */

#endif  /* BRANCH_PREDICTION_H_ */
