libc_crt_target_cflags =
libc_crt_target_so_cflags =

if TARGET_ARCH_IS_ARM
libc_crt_target_cflags += -DCRT_LEGACY_WORKAROUND
endif

if TARGET_ARCH_IS_X86
libc_crt_target_so_cflags += -fPIC
if ARCH_X86_HAVE_SSE2
    libc_crt_target_cflags += -DUSE_SSE2=1
endif
if ARCH_X86_HAVE_SSSE3
    libc_crt_target_cflags += -DUSE_SSSE3=1
endif
endif

libc_crt_target_cflags += -I$(top_srcdir)/libc/private

libc_crt_target_cflags += -I$(top_srcdir)/libc/private -I$(top_srcdir)/libc/arch-@TARGET_ARCH@/include

# Define the libc run-time (crt) support object files that must be built,
# which are needed to build all other objects (shared/static libs and
# executables)
# ==========================================================================

if TARGET_ARCH_IS_X86_OR_ARM
# ARM and x86 need crtbegin_so/crtend_so.
#
# For x86, the .init section must point to a function that calls all
# entries in the .ctors section. (on ARM this is done through the
# .init_array section instead).
#
# For both platforms, the .fini_array section must point to a function
# that will call __cxa_finalize(&__dso_handle) in order to ensure that
# static C++ destructors are properly called on dlclose().
#

libc_crt_target_so_cflags += $(libc_crt_target_cflags)
if TARGET_ARCH_IS_X86
    # This flag must be added for x86 targets, but not for ARM
    libc_crt_target_so_cflags += -fPIC
    libc_crt_target_so_cflags += -m32 -march=i686
endif
$(top_builddir)/libc/crtbegin_so.o: $(top_srcdir)/libc/arch-@TARGET_ARCH@/bionic/crtbegin_so.S
	@mkdir -p $(dir $@)
	@CC@ $(libc_crt_target_so_cflags) -o $@ -c $<
CRTFILES += $(top_builddir)/libc/crtbegin_so.o

$(top_builddir)/libc/crtend_so.o: $(top_srcdir)/libc/arch-@TARGET_ARCH@/bionic/crtend_so.S
	@mkdir -p $(dir $@)
	@CC@ $(libc_crt_target_so_cflags) -o $@ -c $<
CRTFILES += $(top_builddir)/libc/crtend_so.o
endif # TARGET_ARCH == x86 || TARGET_ARCH == arm

$(top_builddir)/libc/crtbegin_static.o: $(top_srcdir)/libc/arch-@TARGET_ARCH@/bionic/crtbegin_static.S
	@mkdir -p $(dir $@)
	@CC@ $(libc_crt_target_cflags) -o $@ -c $<
CRTFILES += $(top_builddir)/libc/crtbegin_static.o

$(top_builddir)/libc/crtbegin_dynamic.o: $(top_srcdir)/libc/arch-@TARGET_ARCH@/bionic/crtbegin_dynamic.S
	@mkdir -p $(dir $@)
	@CC@ $(libc_crt_target_cflags) -o $@ -c $<
CRTFILES += $(top_builddir)/libc/crtbegin_dynamic.o

$(top_builddir)/libc/crtend_android.o: $(top_srcdir)/libc/arch-@TARGET_ARCH@/bionic/crtend.S
	@mkdir -p $(dir $@)
	@CC@ $(libc_crt_target_cflags) -o $@ -c $<
CRTFILES += $(top_builddir)/libc/crtend_android.o
