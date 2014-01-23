ALL_LOCAL =
CLEAN_LOCAL =
INSTALL_LOCAL =

include mk/rules.mk
include libc/Makefile.syscalls.am
include libc/Makefile.crt.am
include libdl/Makefile.am
include libthread_db/Makefile.am
include libc/Makefile.am
include libm/Makefile.am
include libstdc++/Makefile.am
include linker/Makefile.am

all-local: $(ALL_LOCAL)
clean-local: $(CLEAN_LOCAL)
#install-local: $(INSTALL_LOCAL)