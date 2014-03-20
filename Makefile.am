ALL_LOCAL =
CLEAN_LOCAL =
INSTALL_EXEC_LOCAL =

BIONIC_DATADIR = $(datadir)/bionic

include mk/rules.mk
include libc/Makefile.syscalls.am
include libc/Makefile.crt.am
include libdl/Makefile.am
include libthread_db/Makefile.am
include libc/Makefile.am
include libm/Makefile.am
include libstdc++/Makefile.am
include linker/Makefile.am
include libc/zoneinfo/Makefile.am

# headers 
include Makefile.h.am
include Makefile.kh.am

if ! HEADERS_ONLY

all-local: $(ALL_LOCAL)
clean-local: $(CLEAN_LOCAL)
install-exec-local: $(INSTALL_EXEC_LOCAL)

bionicdir   = $(BIONIC_DATADIR)
bionic_DATA = \
	$(addprefix $(top_srcdir)/, \
		AUTHORS \
		ChangeLog \
		COPYING \
		NEWS \
		README \
		TODO \
	)

endif
