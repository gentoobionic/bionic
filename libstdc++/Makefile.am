libstdc@PLUSPLUS@_src = src/new.cpp src/one_time_construction.cpp src/pure_virtual.cpp src/typeinfo.cpp
libstdc@PLUSPLUS@_cxxflags = @COMMON_CFLAGS@
libstdc@PLUSPLUS@_cxxflags += -fno-exceptions -fno-rtti
libstdc@PLUSPLUS@_ldflags = @COMMON_LDFLAGS@ -L$(top_builddir)/libc/
libstdc@PLUSPLUS@_ldlibs  = -lc

libstdc@PLUSPLUS@_cxxflags += -I$(top_srcdir)/libstdc@PLUSPLUS@/include
libstdc@PLUSPLUS@_cxxflags += -I$(top_srcdir)/libc/private

libstdc@PLUSPLUS@_src_files = src/new.cpp src/one_time_construction.cpp src/pure_virtual.cpp src/typeinfo.cpp

libstdc@PLUSPLUS@_src = $(addprefix $(top_srcdir)/libstdc@PLUSPLUS@/,$(libstdc@PLUSPLUS@_src_files))
libstdc@PLUSPLUS@_obj = 
libstdc@PLUSPLUS@_cflags = @COMMON_CFLAGS@ -I$(top_srcdir)/libc/include
libstdc@PLUSPLUS@_ldflags = @COMMON_ldflags@ -shared -Wl,-soname,libstdc@PLUSPLUS@.so
libstdc@PLUSPLUS@_ldlibs = -lc
libstdc@PLUSPLUS@_dep = $(CRTFILES) libc-all

$(foreach f,$(libstdc@PLUSPLUS@_src), $(eval $(call compile-one-file,$(f),libstdc@PLUSPLUS@,$(libstdc@PLUSPLUS@_dep))))

.PHONY: libstdc@PLUSPLUS@-all-local libstdc@PLUSPLUS@-clean-local

$(top_builddir)/libstdc@PLUSPLUS@/libstdc@PLUSPLUS@.a: $(libstdc@PLUSPLUS@_obj)
	mkdir -p $(dir $@)
	@AR@ crsP $@ $^

$(top_builddir)/libstdc@PLUSPLUS@/libstdc@PLUSPLUS@.so: $(libstdc@PLUSPLUS@_obj) $(libstdc@PLUSPLUS@_dependencies)
	@CC@ $(libstdc@PLUSPLUS@_ldflags) -o $@ $(libstdc@PLUSPLUS@_obj) $(libstdc@PLUSPLUS@_ldlibs)

libstdc@PLUSPLUS@-all: $(top_builddir)/libstdc@PLUSPLUS@/libstdc@PLUSPLUS@.a $(top_builddir)/libstdc@PLUSPLUS@/libstdc@PLUSPLUS@.so

libstdc@PLUSPLUS@-clean:
	rm -f $(libstdc@PLUSPLUS@_obj) $(top_builddir)/libstdc@PLUSPLUS@/libstdc@PLUSPLUS@.a $(top_builddir)/libstdc@PLUSPLUS@/libstdc@PLUSPLUS@.so

ALL_LOCAL += libstdc@PLUSPLUS@-all
CLEAN_LOCAL += libstdc@PLUSPLUS@-clean
