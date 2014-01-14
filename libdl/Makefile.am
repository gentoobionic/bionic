lib_LTLIBRARIES = libdl.la
libdl_la_SOURCES = libdl.c
libdl_la_CFLAGS = -Wall -nostdinc -I$(top_srcdir)/libc/include
libdl_la_LDFLAGS = @COMMON_LDFLAGS@

if TARGET_ARCH_IS_X86
libdl_la_LDFLAGS += @COMMON_LDFLAGS_X86@
endif