# The compilation of software known as Bionic is distributed under the
# following terms:
# 
# Copyright (c) Christopher Friedt. All rights reserved.
# 
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions
# are met:
# 1. Redistributions of source code must retain the above copyright
#    notice, this list of conditions and the following disclaimer.
# 2. Redistributions in binary form must reproduce the above copyright
#    notice, this list of conditions and the following disclaimer in the
#    documentation and/or other materials provided with the distribution.
# 
# THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND
# ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
# IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
# ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
# FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
# DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
# OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
# HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
# LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
# OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
# SUCH DAMAGE.

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
		libc/NOTICE \
		libdl/NOTICE \
		libm/NOTICE \
		libstdc++/NOTICE \
		libthread_db/NOTICE \
		linker/NOTICE \
	)

endif
