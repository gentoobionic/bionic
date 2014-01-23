libstdc++_src = \
	$(addprefix $(top_srcdir)/libstdc++/, \
		src/new.cpp \
		src/one_time_construction.cpp \
		src/pure_virtual.cpp \
		src/typeinfo.cpp \
	)
libstdc++_cxxflags = @COMMON_CFLAGS@
libstdc++_cxxflags += -fno-exceptions -fno-rtti
libstdc++_cxxflags += -I$(top_srcdir)/libstdc++/include
libstdc++_cxxflags += -I$(top_srcdir)/libc/private
libstdc++_ldflags = @COMMON_LDFLAGS@ -shared -Wl,-soname,libstdc++.so -L$(top_builddir)/libc/
libstdc++_ldlibs  = -lc
libstdc++_dep = $(CRTFILES) libc-all
libstdc++_obj = 

$(foreach f,$(libstdc++_src), $(eval $(call compile-one-file,$(f),libstdc++,$(libstdc++_dep))))

.PHONY: libstdc++-all-local libstdc++-clean-local

$(top_builddir)/libstdc++/libstdc++.a: $(libstdc++_obj)
	mkdir -p $(dir $@)
	@AR@ crsP $@ $^

$(top_builddir)/libstdc++/libstdc++.so: $(libstdc++_obj) $(libstdc++_dependencies)
	@CC@ $(libstdc++_ldflags) -o $@ $(libstdc++_obj) $(libstdc++_ldlibs)

libstdc++-all: $(SYSCALLS_STAMP) $(top_builddir)/libstdc++/libstdc++.a $(top_builddir)/libstdc++/libstdc++.so

libstdc++-clean:
	rm -f $(libstdc++_obj) $(top_builddir)/libstdc++/libstdc++.a $(top_builddir)/libstdc++/libstdc++.so

ALL_LOCAL += libstdc++-all
CLEAN_LOCAL += libstdc++-clean
