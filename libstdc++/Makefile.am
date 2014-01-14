define compiler-include-path
$(shell echo | @CC@ -v -x c -E - 2>&1 | grep -A 1 "^#include" | tail -n 1)
endef

lib_LTLIBRARIES = libstdc@PLUSPLUS@.la
libstdc@PLUSPLUS@_la_SOURCES = src/new.cpp src/one_time_construction.cpp src/pure_virtual.cpp src/typeinfo.cpp
libstdc@PLUSPLUS@_la_CXXFLAGS = -nostdinc -include $(top_srcdir)/libc/arch-@TARGET_ARCH@/AndroidConfig.h
libstdc@PLUSPLUS@_la_CXXFLAGS += -fno-exceptions -fno-rtti
libstdc@PLUSPLUS@_la_CPPFLAGS = -I$(call compiler-include-path)
libstdc@PLUSPLUS@_la_LDFLAGS = @COMMON_LDFLAGS@

if TARGET_ARCH_IS_X86
libstdc@PLUSPLUS@_la_CXXFLAGS += -march=i686 -m32
libstdc@PLUSPLUS@_la_CPPFLAGS += -I$(top_srcdir)/libc/arch-x86/include
libstdc@PLUSPLUS@_la_CPPFLAGS += -I$(top_srcdir)/libc/kernel/arch-x86
libstdc@PLUSPLUS@_la_LDFLAGS += @COMMON_LDFLAGS_X86@
endif

libstdc@PLUSPLUS@_la_CPPFLAGS += -I$(top_srcdir)/libm/include
libstdc@PLUSPLUS@_la_CPPFLAGS += -I$(top_srcdir)/libc/include
libstdc@PLUSPLUS@_la_CPPFLAGS += -I$(top_srcdir)/libc/kernel/common/linux -I$(top_srcdir)/libc/kernel/common
libstdc@PLUSPLUS@_la_CPPFLAGS += -I$(top_srcdir)/libthread_db/include
libstdc@PLUSPLUS@_la_CPPFLAGS += -I$(top_srcdir)/libstdc@PLUSPLUS@/include
libstdc@PLUSPLUS@_la_CPPFLAGS += -I$(top_srcdir)/libc/private