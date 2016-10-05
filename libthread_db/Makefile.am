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

libthread_db_cflags = @COMMON_CFLAGS@
libthread_db_ldflags = $(subst -Wl$(COMMA)-no-undefined,,@COMMON_LDFLAGS@)
libthread_db_ldflags += -Bsymbolic -shared -Wl,-soname,libthread_db.so
libthread_db_ldlibs = -lc -ldl

libthread_db_src_files = libthread_db/libthread_db.c

libthread_db_src = $(addprefix $(top_srcdir)/,$(libthread_db_src_files))
libthread_db_obj = 
libthread_db_dep = $(CRTFILES) libc-all libdl-all

$(foreach f,$(libthread_db_src), $(eval $(call compile-one-file,$(f),libthread_db,$(libthread_db_dep))))

.PHONY: libthread_db-all-local libthread_db-clean-local libthread_db-install-exec-local

$(top_builddir)/libthread_db/libthread_db.a: $(libthread_db_obj)
	mkdir -p $(dir $@)
	@AR@ crsP $@ $^

$(top_builddir)/libthread_db/libthread_db.so: $(libthread_db_obj) $(libthread_db_dep)
	mkdir -p $(dir $@)
	@CC@ $(libthread_db_ldflags) -o $@ $(CRTBEGIN_SO) $(libthread_db_obj) $(libthread_db_ldlibs) $(CRTEND_SO)

libthread_db-all: $(top_builddir)/libthread_db/libthread_db.a $(top_builddir)/libthread_db/libthread_db.so

libthread_db-clean:
	rm -f $(libthread_db_obj) $(top_builddir)/libthread_db/libthread_db.a $(top_builddir)/libthread_db/libthread_db.so

# /lib is the standard place for C shared libraries, so create a symlink to that in /usr/lib
libthread_db-install-exec-local: libthread_db-all
	$(INSTALL) -m 644 -D $(top_builddir)/libthread_db/libthread_db.a $(DESTDIR)$(libdir)/libthread_db.a
	$(INSTALL) -m 644 -D $(top_builddir)/libthread_db/libthread_db.so $(DESTDIR)$(libdir)/libthread_db.so
	if [ "$(libdir)" != "/lib" ]; then \
		$(INSTALL) -d $(DESTDIR)/lib && \
		cd $(DESTDIR)/lib && \
		ln -sf $(libdir)/libthread_db.so .; \
	fi

if ! HEADERS_ONLY

libthreaddbdir   = $(BIONIC_DATADIR)/libthread_db
libthreaddb_DATA = \
	$(addprefix libthread_db/, \
		MODULE_LICENSE_BSD \
		NOTICE \
	)

endif

ALL_LOCAL += libthread_db-all
CLEAN_LOCAL += libthread_db-clean
INSTALL_EXEC_LOCAL += libthread_db-install-exec-local
