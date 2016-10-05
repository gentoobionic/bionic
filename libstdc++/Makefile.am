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

libstdc++_src_files = \
	src/new.cpp \
	src/one_time_construction.cpp \
	src/pure_virtual.cpp \
	src/typeinfo.cpp

libstdc++_src = $(addprefix $(top_srcdir)/libstdc++/,$(libstdc++_src_files)) 
libstdc++_cxxflags = @COMMON_CFLAGS@
libstdc++_cxxflags += -fno-exceptions -fno-rtti
libstdc++_cxxflags += -fno-use-cxa-atexit
libstdc++_cxxflags += -I$(top_srcdir)/libstdc++/include
libstdc++_cxxflags += -I$(top_srcdir)/libc/private
libstdc++_ldflags = @COMMON_LDFLAGS@
libstdc++_ldflags += -Bsymbolic -shared -Wl,-soname,libstdc++.so
libstdc++_ldlibs  = @COMMON_LDLIBS@ -lc
libstdc++_dep = $(CRTFILES) libc-all
libstdc++_obj =

$(foreach f,$(libstdc++_src), $(eval $(call compile-one-file,$(f),libstdc++,$(libstdc++_dep))))

.PHONY: libstdc++-all-local libstdc++-clean-local libstdc++-install-exec-local

$(top_builddir)/libstdc++/libstdc++.a: $(libstdc++_obj)
	mkdir -p $(dir $@)
	@AR@ crsP $@ $^

$(top_builddir)/libstdc++/libstdc++.so: $(libstdc++_obj)  $(top_builddir)/libc/libc.so
	mkdir -p $(dir $@)
	@CC@ $(libstdc++_ldflags) -o $@ $(CRTBEGIN_SO) $(libstdc++_obj) $(libstdc++_ldlibs) $(CRTEND_SO)

libstdc++-all: $(SYSCALLS_STAMP) $(top_builddir)/libstdc++/libstdc++.a $(top_builddir)/libstdc++/libstdc++.so

libstdc++-clean:
	rm -f $(libstdc++_obj) $(top_builddir)/libstdc++/libstdc++.a $(top_builddir)/libstdc++/libstdc++.so

if ENABLE_CXX

# /lib is the standard place for C shared libraries, so create a symlink to that in /usr/lib 
libstdc++-install-exec-local: libstdc++-all
	$(INSTALL) -m 644 -D $(top_builddir)/libstdc++/libstdc++.a $(DESTDIR)$(libdir)/libstdc++.a
	$(INSTALL) -m 644 -D $(top_builddir)/libstdc++/libstdc++.so $(DESTDIR)$(libdir)/libstdc++.so
	if [ "$(libdir)" != "/lib" ]; then \
		$(INSTALL) -d $(DESTDIR)/lib && \
		cd $(DESTDIR)/lib && \
		ln -sf $(libdir)/libstdc++.so .; \
	fi

if ! HEADERS_ONLY

libstdc++dir   = $(BIONIC_DATADIR)/libstdc++
libstdc++_DATA = \
	$(addprefix libstdc++/, \
		MODULE_LICENSE_BSD \
		NOTICE \
	)

endif

ALL_LOCAL += libstdc++-all
CLEAN_LOCAL += libstdc++-clean
INSTALL_EXEC_LOCAL += libstdc++-install-exec-local

endif