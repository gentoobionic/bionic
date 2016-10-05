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

.PHONY: linker-all linker-clean linker-install linker-install-exec-local

linker_common_cflags = $(subst -UDEBUG,,$(subst -DDEBUG,,@COMMON_CFLAGS@))
linker_common_cflags += -DANDROID_$(shell echo @TARGET_ARCH@ | tr [:lower:] [:upper:])_LINKER
linker_common_cflags += -fno-stack-protector -Wstrict-overflow=5 -fvisibility=hidden
linker_common_cflags += -I$(top_srcdir)/libc/private
linker_common_cflags += -I$(top_srcdir)/linker/include

# ========================================================
# begin.o
# ========================================================

begin_src_files = arch/@TARGET_ARCH@/begin.S

begin_cflags = $(linker_common_cflags)

begin_src = $(addprefix $(top_srcdir)/linker/,$(begin_src_files))
begin_obj =
begin_dep =
$(foreach f,$(begin_src), $(eval $(call compile-one-file,$(f),begin,$(begin_dep))))

# ========================================================
# linker
# ========================================================

linker_src_files = linker.c linker_format.c linker_environ.c dlfcn.c rt.c debugger.c

linker_cflags = $(linker_common_cflags)

linker_ldflags = -shared -Wl,--exclude-libs,ALL
linker_ldflags += -Bstatic @COMMON_LDFLAGS@

linker_src = $(addprefix $(top_srcdir)/linker/,$(linker_src_files))
linker_obj =
linker_dep = $(begin_obj) libc-all
$(foreach f,$(linker_src), $(eval $(call compile-one-file,$(f),linker,$(linker_dep))))

$(top_builddir)/linker/linker: $(begin_obj) $(linker_obj) $(top_builddir)/libc/libc_nomalloc.a
	mkdir -p $(dir $@)
	@CC@ -o $@ $(linker_ldflags) $(begin_obj) $(linker_obj) -Wl,--start-group $(top_builddir)/libc/libc_nomalloc.a @COMMON_LDLIBS@ -Wl,--end-group
	@OBJCOPY@ --prefix-symbols=__dl_ $@

# ========================================================
# common targets
# ========================================================

linker-all: $(top_builddir)/linker/linker

linker-clean:
	rm -f $(top_builddir)/linker/linker \
		$(linker_obj) \
		$(begin_obj)

# the linker is hard-coded at /bin/linker
linker-install-exec-local: linker-all
	$(INSTALL) -m 755 -D $(top_builddir)/linker/linker $(DESTDIR)/bin/linker

if ! HEADERS_ONLY

linkerdir   = $(BIONIC_DATADIR)/linker
linker_DATA = \
	$(addprefix linker/, \
		MODULE_LICENSE_APACHE2 \
		NOTICE \
		README.TXT \
	)

endif

ALL_LOCAL += linker-all
CLEAN_LOCAL += linker-clean
INSTALL_EXEC_LOCAL += linker-install-exec-local
