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

libdldir   = $(BIONIC_DATADIR)/libdl
libdl_DATA = \
	$(addprefix libdl/, \
		MODULE_LICENSE_BSD \
		NOTICE \
	)

ALL_LOCAL += libdl-all
CLEAN_LOCAL += libdl-clean
INSTALL_EXEC_LOCAL += libdl-install-exec-local
