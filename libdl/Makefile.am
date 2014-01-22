libdl_src = libdl/libdl.c
libdl_obj = 
libdl_cflags = -Wall -nostdinc -I$(top_srcdir)/libc/include
libdl_ldflags = @COMMON_LDFLAGS@ -shared -Wl,-soname,libdl.so
libdl_dependencies = $(CRTFILES)

define compile-one-libdl-file
$(eval _tgt = $(call subst-src-ext,$(1)))
$(eval libdl_obj += $(_tgt))
$(call compile-one-file,$(1),$(_tgt),$(libdl_cflags))
endef

$(foreach f,$(libdl_src),$(eval $(call compile-one-libdl-file,$(f))))

.PHONY: libdl-all-local libdl-clean-local

$(top_builddir)/libdl/libdl.a: $(libdl_obj)
	mkdir -p $(dir $@)
	@AR@ crsP $@ $^

$(top_builddir)/libdl/libdl.so: $(libdl_obj) $(libdl_dependencies)
	@CC@ $(libdl_ldflags) -o $@ $(libdl_obj)

libdl-all-local: $(top_builddir)/libdl/libdl.a $(top_builddir)/libdl/libdl.so

libdl-clean-local:
	rm -f $(libdl_obj) $(top_builddir)/libdl/libdl.a $(top_builddir)/libdl/libdl.so

ALL_LOCAL += libdl-all-local
CLEAN_LOCAL += libdl-clean-local