define compiler-include-path
$(shell echo | @CC@ -v -x c -E - 2>&1 | grep -A 1 "^#include" | tail -n 1)
endef

.deps/linker.Plo:
	mkdir -p $(dir $@)
	touch $@

bin_PROGRAMS = linker
linker_SOURCES = linker.c linker_format.c linker_environ.c dlfcn.c debugger.c rt.c
linker_CFLAGS = -DLINKER_DEBUG=0 -nostartfiles -nostdinc -include $(top_srcdir)/libc/arch-@TARGET_ARCH@/AndroidConfig.h
linker_CFLAGS += -fno-stack-protector -Wstrict-overflow=5 -fvisibility=hidden
linker_CFLAGS += -I$(call compiler-include-path)
linker_CFLAGS += -I$(top_srcdir)/libc/include
linker_LDFLAGS = -Wl,-no-undefined -nodefaultlibs -L$(top_builddir) -L$(top_builddir)/libc/.libs
linker_LDADD = -lc_static -lgcc

linker_CFLAGS += -I$(top_srcdir)/libc/arch-@TARGET_ARCH@/include
linker_CFLAGS += -I$(top_srcdir)/libc/kernel/arch-@TARGET_ARCH@

if TARGET_ARCH_IS_X86
linker_CFLAGS += -march=i686 -m32 -DANDROID_X86_LINKER
endif

if TARGET_ARCH_IS_ARM
if ARCH_ARM_HAVE_TLS_REGISTER
linker_CFLAGS += -DHAVE_ARM_TLS_REGISTER -DANDROID_ARM_LINKER
endif
endif 

if TARGET_ARCH_IS_X86_OR_ARM
linker_SOURCES += arch/@TARGET_ARCH@/begin.S
endif

linker_CFLAGS += -I$(top_srcdir)/libc/include
linker_CFLAGS += -I$(top_srcdir)/libc/private
linker_CFLAGS += -I$(top_srcdir)/libc/kernel/common/linux -I$(top_srcdir)/libc/kernel/common
linker_CFLAGS += -I$(top_srcdir)/linker/include
