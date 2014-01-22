common_ldflags = @COMMON_LDFLAGS@
my_ldflags = $(common_ldflags:-Wl,-no-undefined=)
my_ldflags += -shared -Wl,-soname,"libthread_db.so"

libthread_db_cflags = @COMMON_CFLAGS@
libthread_db_ldflags = $(my_ldflags) -L$(top_builddir)/libdl -L$(top_builddir)/libc
libthread_db_ldlibs = -ldl -lc

if TARGET_ARCH_IS_X86
libthread_db_cflags += -march=i686 -m32
libthread_db_cflags += -I$(top_srcdir)/libc/arch-x86/include
libthread_db_cflags += -I$(top_srcdir)/libc/kernel/arch-x86
endif

libthread_db_cflags += -I$(top_srcdir)/libm/include
libthread_db_cflags += -I$(top_srcdir)/libc/include
libthread_db_cflags += -I$(top_srcdir)/libc/kernel/common/linux -I$(top_srcdir)/libc/kernel/common
libthread_db_cflags += -I$(top_srcdir)/libthread_db/include

libthread_db_src = libthread_db/libthread_db.c
libthread_db_obj = 
libthread_db_dependencies = $(CRTFILES)

$(foreach f,$(libthread_db_src), $(eval $(call compile-one-file,$(f),libthread_db,$(libthread_db_dependencies))))

.PHONY: libthread_db-all-local libthread_db-clean-local

$(top_builddir)/libthread_db/libthread_db.a: $(libthread_db_obj)
	mkdir -p $(dir $@)
	@AR@ crsP $@ $^

$(top_builddir)/libthread_db/libthread_db.so: $(libthread_db_obj) $(libthread_db_dependencies)
	@CC@ $(libthread_db_ldflags) -o $@ $(libthread_db_obj) $(libthread_db_ldlibs)

libthread_db-all: $(top_builddir)/libthread_db/libthread_db.a $(top_builddir)/libthread_db/libthread_db.so

libthread_db-clean:
	rm -f $(libthread_db_obj) $(top_builddir)/libthread_db/libthread_db.a $(top_builddir)/libthread_db/libthread_db.so

ALL_LOCAL += libthread_db-all
CLEAN_LOCAL += libthread_db-clean