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

libdl_src_files = libdl.c
libdl_src = $(addprefix $(top_srcdir)/libdl/,$(libdl_src_files))
libdl_obj = 
libdl_cflags = @COMMON_CFLAGS@ -I$(top_srcdir)/libc/include
libdl_ldflags = $(subst -Wl$(COMMA)-no-undefined,,@COMMON_LDFLAGS@)
libdl_ldflags += -Bsymbolic -shared -Wl,-soname,libdl.so
libdl_dep = $(CRTFILES)

$(foreach f,$(libdl_src), $(eval $(call compile-one-file,$(f),libdl,$(libdl_dep))))

.PHONY: libdl-all-local libdl-clean-local libdl-install-exec-local

$(top_builddir)/libdl/libdl.a: $(libdl_obj)
	mkdir -p $(dir $@)
	@AR@ crsP $@ $^

$(top_builddir)/libdl/libdl.so: $(libdl_obj) $(libdl_dependencies)
	mkdir -p $(dir $@)
	@CC@ $(libdl_ldflags) -o $@ $(CRTBEGIN_SO) $(libdl_obj) $(libdl_ldlibs) $(CRTEND_SO)

libdl-all: $(top_builddir)/libdl/libdl.a $(top_builddir)/libdl/libdl.so

libdl-clean:
	rm -f $(libdl_obj) $(top_builddir)/libdl/libdl.a $(top_builddir)/libdl/libdl.so

# /lib is the standard place for C shared libraries, so create a symlink to that in /usr/lib
libdl-install-exec-local: libdl-all
	$(INSTALL) -m 644 -D $(top_builddir)/libdl/libdl.a $(DESTDIR)$(libdir)/libdl.a
	$(INSTALL) -m 644 -D $(top_builddir)/libdl/libdl.so $(DESTDIR)$(libdir)/libdl.so
	if [ "$(libdir)" != "/lib" ]; then \
		$(INSTALL) -d $(DESTDIR)/lib && \
		cd $(DESTDIR)/lib && \
		ln -sf $(libdir)/libdl.so .; \
	fi

if ! HEADERS_ONLY

libdldir   = $(BIONIC_DATADIR)/libdl
libdl_DATA = \
	$(addprefix libdl/, \
		MODULE_LICENSE_BSD \
		NOTICE \
	)

endif

ALL_LOCAL += libdl-all
CLEAN_LOCAL += libdl-clean
INSTALL_EXEC_LOCAL += libdl-install-exec-local
