libdl_src = libdl/libdl.c
libdl_obj = 
libdl_cflags = @COMMON_CFLAGS@ -I$(top_srcdir)/libc/include
libdl_ldflags = @COMMON_LDFLAGS@ -shared -Wl,-soname,libdl.so
libdl_dependencies = $(CRTFILES)

$(foreach f,$(libdl_src), $(eval $(call compile-one-file,$(f),libdl)))

.PHONY: libdl-all-local libdl-clean-local

$(top_builddir)/libdl/libdl.a: $(libdl_obj)
	mkdir -p $(dir $@)
	@AR@ crsP $@ $^

$(top_builddir)/libdl/libdl.so: $(libdl_obj) $(libdl_dependencies)
	@CC@ $(libdl_ldflags) -o $@ $(libdl_obj)

libdl-all: $(top_builddir)/libdl/libdl.a $(top_builddir)/libdl/libdl.so

libdl-clean:
	rm -f $(libdl_obj) $(top_builddir)/libdl/libdl.a $(top_builddir)/libdl/libdl.so

ALL_LOCAL += libdl-all
CLEAN_LOCAL += libdl-clean