linker_src_files = linker.c linker_format.c linker_environ.c dlfcn.c debugger.c rt.c
linker_cflags =  @COMMON_CFLAGS@ -DLINKER_DEBUG=0 -static-libgcc
linker_cflags += -fno-stack-protector -Wstrict-overflow=5 -fvisibility=hidden
linker_cflags += -I$(top_srcdir)/libc/private
linker_cflags += -I$(top_srcdir)/linker/include
linker_ldflags = $(subst -Wl$(COMMA)--exclude-libs=libgcc_eh.a,,$(subst -Wl$(COMMA)--exclude-libs=libgcc.a,,@COMMON_LDFLAGS@))
linker_ldflags += -Bstatic -shared 
linker_ldlibs = -lgcc
linker_dep = libc-all

if TARGET_ARCH_IS_X86
linker_cflags += -DANDROID_X86_LINKER
endif

if TARGET_ARCH_IS_ARM
if ARCH_ARM_HAVE_TLS_REGISTER
linker_cflags += -DHAVE_ARM_TLS_REGISTER
endif
linker_cflags += -DANDROID_ARM_LINKER
endif 

if TARGET_ARCH_IS_X86_OR_ARM
begin_src_files = arch/@TARGET_ARCH@/begin.S
endif

begin_src = $(addprefix $(top_srcdir)/linker/,$(begin_src_files))
begin_cflags = $(linker_cflags)
begin_obj =
$(foreach f,$(begin_src), $(eval $(call compile-one-file,$(f),begin,$(begin_dep))))

linker_src = $(addprefix $(top_srcdir)/linker/,$(linker_src_files))
linker_obj =
$(foreach f,$(linker_src), $(eval $(call compile-one-file,$(f),linker,$(linker_dep))))

$(top_builddir)/linker/linker: $(begin_obj) $(linker_obj) libc-all
	@CC@ -o $@ -Wl,--start-group $(begin_obj) $(linker_ldflags) $(linker_obj) $(top_builddir)/libc/libc.a $(linker_ldlibs) -Wl,--end-group

.PHONY: linker-all linker-clean linker-install linker-install-exec-local

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
