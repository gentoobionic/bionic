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
libstdc++_ldlibs  = -lc
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

libstdc++-install-exec-local: libstdc++-all
	$(INSTALL) -D $(top_builddir)/libstdc++/libstdc++.a $(DESTDIR)$(libdir)/libstdc++.a
	$(INSTALL) -D $(top_builddir)/libstdc++/libstdc++.so $(DESTDIR)$(libdir)/libstdc++.so

ALL_LOCAL += libstdc++-all
CLEAN_LOCAL += libstdc++-clean
INSTALL_EXEC_LOCAL += libstdc++-install-exec-local
