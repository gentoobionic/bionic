#ifndef ETHER_PRIV_H_
#define ETHER_PRIV_H_

#define ETHERS_FILENAME "/etc/ethers"

#ifdef _POSIX_HOST_NAME_MAX
#define POSIX_HOST_NAME_MAX _POSIX_HOST_NAME_MAX
#else
#define POSIX_HOST_NAME_MAX 255
#endif

#endif /* ETHER_PRIV_H_ */
