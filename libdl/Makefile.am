libdl_src = libdl/libdl.c
libdl_obj = 
libdl_cflags = @COMMON_CFLAGS@ -I$(top_srcdir)/libc/include
libdl_ldflags = $(subst -Wl$(COMMA)-no-undefined,,@COMMON_LDFLAGS@)
libdl_ldflags += -shared -Wl,-soname,libdl.so
libdl_dep = $(CRTFILES)

$(foreach f,$(libdl_src), $(eval $(call compile-one-file,$(f),libdl,$(libdl_dep))))

.PHONY: libdl-all-local libdl-clean-local libdl-install-exec-local

$(top_builddir)/libdl/libdl.a: $(libdl_obj)
	mkdir -p $(dir $@)
	@AR@ crsP $@ $^

$(top_builddir)/libdl/libdl.so: $(libdl_obj) $(libdl_dependencies)
	@CC@ $(libdl_ldflags) -o $@ $(CRTBEGIN_SO) $(libdl_obj) $(CRTEND_SO)

libdl-all: $(top_builddir)/libdl/libdl.a $(top_builddir)/libdl/libdl.so

libdl-clean:
	rm -f $(libdl_obj) $(top_builddir)/libdl/libdl.a $(top_builddir)/libdl/libdl.so

libdl-install-exec-local: libdl-all
	$(INSTALL) -D $(top_builddir)/libdl/libdl.a $(DESTDIR)$(libdir)/libdl.a
	$(INSTALL) -D $(top_builddir)/libdl/libdl.so $(DESTDIR)$(libdir)/libdl.so

ALL_LOCAL += libdl-all
CLEAN_LOCAL += libdl-clean
INSTALL_EXEC_LOCAL += libdl-install-exec-local
