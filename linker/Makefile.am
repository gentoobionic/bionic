.PHONY: linker-all linker-clean linker-install linker-install-exec-local

linker_common_cflags = @COMMON_CFLAGS@
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

linker_src_files = linker.c linker_format.c linker_environ.c dlfcn.c debugger.c rt.c

linker_cflags = $(linker_common_cflags)

linker_ldflags = @COMMON_LDFLAGS@
linker_ldflags += -Bstatic -shared
linker_ldflags += -L$(top_builddir)/libc
linker_ldlibs = -lc_nomalloc -lgcc

linker_src = $(addprefix $(top_srcdir)/linker/,$(linker_src_files))
linker_obj =
linker_dep = libc-all
$(foreach f,$(linker_src), $(eval $(call compile-one-file,$(f),linker,$(linker_dep))))

$(top_builddir)/linker/linker: $(begin_obj) $(linker_obj)
	mkdir -p $(dir $@)
	@CC@ -o $@ $(linker_ldflags) -Wl,--start-group $(begin_obj) $(linker_obj) $(linker_ldlibs) -Wl,--end-group

#	$(OBJCOPY) --prefix-symbols __dl_ $@.tmp || rm $@.tmp $@ 2&>/dev/null
#	mv $@.tmp $@  

# ========================================================
# common targets
# ========================================================

linker-all: $(top_builddir)/linker/linker

linker-clean:
	rm -f $(top_builddir)/linker/linker \
		$(linker_obj) \
		$(begin_obj)

linker-install-exec-local: linker-all
	$(INSTALL) -D $(top_builddir)/linker/linker $(DESTDIR)/$(bindir)/linker

ALL_LOCAL += linker-all
CLEAN_LOCAL += linker-clean
INSTALL_EXEC_LOCAL += linker-install-exec-local
