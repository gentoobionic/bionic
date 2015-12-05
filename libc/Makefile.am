.PHONY: libc-all libc-clean libc-install-exec-local

# Define the common source files for all the libc instances
# =========================================================
libc_common_src_files = \
	unistd/abort.c \
	unistd/alarm.c \
	unistd/brk.c \
	unistd/creat.c \
	unistd/crypt.c \
	unistd/daemon.c \
	unistd/eventfd.c \
	unistd/exec.c \
	unistd/fcntl.c \
	unistd/fnmatch.c \
	unistd/fstatfs.c \
	unistd/ftime.c \
	unistd/ftok.c \
	unistd/getcwd.c \
	unistd/getdtablesize.c \
	unistd/gethostname.c \
	unistd/getlogin.c \
	unistd/getopt_long.c \
	unistd/getpagesize.c \
	unistd/getpgrp.c \
	unistd/getpriority.c \
	unistd/getpt.c \
	unistd/getusershell.c \
	unistd/initgroups.c \
	unistd/isatty.c \
	unistd/issetugid.c \
	unistd/killpg.c \
	unistd/lseek64.c \
	unistd/mmap.c \
	unistd/nice.c \
	unistd/open.c \
	unistd/openat.c \
	unistd/opendir.c \
	unistd/openpty.c \
	unistd/pathconf.c \
	unistd/perror.c \
	unistd/popen.c \
	unistd/posix_openpt.c \
	unistd/pread.c \
	unistd/pselect.c \
	unistd/ptsname.c \
	unistd/ptsname_r.c \
	unistd/pwrite.c \
	unistd/raise.c \
	unistd/reboot.c \
	unistd/recv.c \
	unistd/sbrk.c \
	unistd/send.c \
	unistd/setegid.c \
	unistd/setuid.c \
	unistd/seteuid.c \
	unistd/setreuid.c \
	unistd/setresuid.c \
	unistd/setpgrp.c \
	unistd/sigblock.c \
	unistd/siginterrupt.c \
	unistd/siglist.c \
	unistd/signal.c \
	unistd/signame.c \
	unistd/sigsetmask.c \
	unistd/sigsuspend.c \
	unistd/sigwait.c \
	unistd/sleep.c \
	unistd/statfs.c \
	unistd/strsignal.c \
	unistd/syslog.c \
	unistd/system.c \
	unistd/tcgetpgrp.c \
	unistd/tcsetpgrp.c \
	unistd/time.c \
	unistd/ttyname.c \
	unistd/umount.c \
	unistd/unlockpt.c \
	unistd/usleep.c \
	unistd/wait.c \
	stdio/asprintf.c \
	stdio/clrerr.c \
	stdio/fclose.c \
	stdio/fdopen.c \
	stdio/feof.c \
	stdio/ferror.c \
	stdio/fflush.c \
	stdio/fgetc.c \
	stdio/fgetln.c \
	stdio/fgetpos.c \
	stdio/fgets.c \
	stdio/fileno.c \
	stdio/findfp.c \
	stdio/flags.c \
	stdio/flockfile.c \
	stdio/fopen.c \
	stdio/fprintf.c \
	stdio/fpurge.c \
	stdio/fputc.c \
	stdio/fputs.c \
	stdio/fread.c \
	stdio/freopen.c \
	stdio/fscanf.c \
	stdio/fseek.c \
	stdio/fsetpos.c \
	stdio/ftell.c \
	stdio/funopen.c \
	stdio/fvwrite.c \
	stdio/fwalk.c \
	stdio/fwrite.c \
	stdio/getc.c \
	stdio/getchar.c \
	stdio/getdelim.c \
	stdio/getline.c \
	stdio/gets.c \
	stdio/glob.c \
	stdio/makebuf.c \
	stdio/mktemp.c \
	stdio/printf.c \
	stdio/putc.c \
	stdio/putchar.c \
	stdio/puts.c \
	stdio/putw.c \
	stdio/refill.c \
	stdio/remove.c \
	stdio/rewind.c \
	stdio/rget.c \
	stdio/scanf.c \
	stdio/setbuf.c \
	stdio/setbuffer.c \
	stdio/setvbuf.c \
	stdio/snprintf.c\
	stdio/sprintf.c \
	stdio/sscanf.c \
	stdio/stdio.c \
	stdio/tempnam.c \
	stdio/tmpfile.c \
	stdio/tmpnam.c \
	stdio/ungetc.c \
	stdio/vasprintf.c \
	stdio/vfprintf.c \
	stdio/vfscanf.c \
	stdio/vprintf.c \
	stdio/vsnprintf.c \
	stdio/vsprintf.c \
	stdio/vscanf.c \
	stdio/vsscanf.c \
	stdio/wbuf.c \
	stdio/wsetup.c \
	stdlib/_rand48.c \
	stdlib/assert.c \
	stdlib/atexit.c \
	stdlib/atoi.c \
	stdlib/atol.c \
	stdlib/atoll.c \
	stdlib/bsearch.c \
	stdlib/ctype_.c \
	stdlib/div.c \
	stdlib/exit.c \
	stdlib/getenv.c \
	stdlib/jrand48.c \
	stdlib/ldiv.c \
	stdlib/lldiv.c \
	stdlib/locale.c \
	stdlib/lrand48.c \
	stdlib/mrand48.c \
	stdlib/nrand48.c \
	stdlib/putenv.c \
	stdlib/qsort.c \
	stdlib/seed48.c \
	stdlib/setenv.c \
	stdlib/setjmperr.c \
	stdlib/srand48.c \
	stdlib/strntoimax.c \
	stdlib/strntoumax.c \
	stdlib/strtod.c \
	stdlib/strtoimax.c \
	stdlib/strtol.c \
	stdlib/strtoll.c \
	stdlib/strtoul.c \
	stdlib/strtoull.c \
	stdlib/strtoumax.c \
	stdlib/tolower_.c \
	stdlib/toupper_.c \
	stdlib/wchar.c \
	string/index.c \
	string/memccpy.c \
	string/mempcpy.c \
	string/memchr.c \
	string/memmem.c \
	string/memrchr.c \
	string/memswap.c \
	string/strcasecmp.c \
	string/strcasestr.c \
	string/strcat.c \
	string/strchr.c \
	string/strchrnul.c \
	string/strcoll.c \
	string/strcspn.c \
	string/strdup.c \
	string/strerror.c \
	string/strerror_r.c \
	string/strlcat.c \
	string/strlcpy.c \
	string/strncat.c \
	string/strncpy.c \
	string/strndup.c \
	string/strnlen.c \
	string/strpbrk.c \
	string/strrchr.c \
	string/strsep.c \
	string/strspn.c \
	string/strstr.c \
	string/strtok.c \
	string/strtotimeval.c \
	string/strxfrm.c \
	wchar/wcpcpy.c \
	wchar/wcpncpy.c \
	wchar/wcscasecmp.c \
	wchar/wcscat.c \
	wchar/wcschr.c \
	wchar/wcscmp.c \
	wchar/wcscoll.c \
	wchar/wcscpy.c \
	wchar/wcscspn.c \
	wchar/wcsdup.c \
	wchar/wcslcat.c \
	wchar/wcslcpy.c \
	wchar/wcslen.c \
	wchar/wcsncasecmp.c \
	wchar/wcsncat.c \
	wchar/wcsncmp.c \
	wchar/wcsncpy.c \
	wchar/wcsnlen.c \
	wchar/wcspbrk.c \
	wchar/wcsrchr.c \
	wchar/wcsspn.c \
	wchar/wcsstr.c \
	wchar/wcstok.c \
	wchar/wcswidth.c \
	wchar/wcsxfrm.c \
	wchar/wmemchr.c \
	wchar/wmemcmp.c \
	wchar/wmemcpy.c \
	wchar/wmemmove.c \
	wchar/wmemset.c \
	inet/bindresvport.c \
	inet/inet_addr.c \
	inet/inet_aton.c \
	inet/inet_ntoa.c \
	inet/inet_ntop.c \
	inet/inet_pton.c \
	inet/ether_aton.c \
	inet/ether_ntoa.c \
	tzcode/asctime.c \
	tzcode/difftime.c \
	tzcode/localtime.c \
	tzcode/strftime.c \
	tzcode/strptime.c \
	bionic/__set_errno.c \
	bionic/cpuacct.c \
	bionic/arc4random.c \
	bionic/basename.c \
	bionic/basename_r.c \
	bionic/clearenv.c \
	bionic/dirname.c \
	bionic/dirname_r.c \
	bionic/drand48.c \
	bionic/erand48.c \
	bionic/err.c \
	bionic/fdprintf.c \
	bionic/fork.c \
	bionic/fts.c \
	bionic/if_nametoindex.c \
	bionic/if_indextoname.c \
	bionic/ioctl.c \
	bionic/ldexp.c \
	bionic/libc_init_common.c \
	bionic/md5.c \
	bionic/memmove_words.c \
	bionic/pututline.c \
	bionic/realpath.c \
	bionic/__register_frame_info.c \
	bionic/sched_getaffinity.c \
	bionic/sched_getcpu.c \
	bionic/sched_cpualloc.c \
	bionic/sched_cpucount.c \
	bionic/semaphore.c \
	bionic/sha1.c \
	bionic/ssp.c \
	bionic/tdelete.c \
	bionic/tdestroy.c \
	bionic/time64.c \
	bionic/tfind.c \
	bionic/thread_atexit.c \
	bionic/tsearch.c \
	bionic/utime.c \
	bionic/utmp.c \
	netbsd/gethnamaddr.c \
	netbsd/isc/ev_timers.c \
	netbsd/isc/ev_streams.c \
	netbsd/inet/nsap_addr.c \
	netbsd/resolv/__dn_comp.c \
	netbsd/resolv/__res_close.c \
	netbsd/resolv/__res_send.c \
	netbsd/resolv/herror.c \
	netbsd/resolv/res_comp.c \
	netbsd/resolv/res_data.c \
	netbsd/resolv/res_debug.c \
	netbsd/resolv/res_init.c \
	netbsd/resolv/res_mkquery.c \
	netbsd/resolv/res_query.c \
	netbsd/resolv/res_send.c \
	netbsd/resolv/res_state.c \
	netbsd/resolv/res_cache.c \
	netbsd/net/nsdispatch.c \
	netbsd/net/getaddrinfo.c \
	netbsd/net/getnameinfo.c \
	netbsd/net/getservbyname.c \
	netbsd/net/getservent.c \
	netbsd/net/base64.c \
	netbsd/net/getservbyport.c \
	netbsd/nameser/ns_name.c \
	netbsd/nameser/ns_parse.c \
	netbsd/nameser/ns_ttl.c \
	netbsd/nameser/ns_netint.c \
	netbsd/nameser/ns_print.c \
	netbsd/nameser/ns_samedomain.c \
	netdb/getnetbyaddr.c \
	netdb/getnetbyname.c \
	netdb/getprotobyname.c \
	netdb/getprotobynumber.c \
	netinet/ether_hostton.c \
	netinet/ether_line.c \
	regex/regcomp.c \
	regex/regerror.c \
	regex/regexec.c \
	regex/regfree.c \
	shadow/endspent.c \
	shadow/fgetspent.c \
	shadow/getspent.c \
	shadow/getspnam.c \
	shadow/lckpwdf.c \
	shadow/putspent.c \
	shadow/setspent.c \
	shadow/sgetspent.c \
	shadow/ulckpwdf.c \
	termios/tcdrain.c \
	utmp/getutid.c \
	utmp/getutline.c \
	grp/getgrent.c \
	grp/getgrgid.c \
	grp/getgrnam.c \
	grp/getgrouplist.c \
	mntent/addmntent.c \
	mntent/endmntent.c \
	mntent/getmntent.c \
	mntent/hasmntopt.c \
	mntent/setmntent.c \
	pwd/getpwent.c \
	pwd/getpwnam.c \
	pwd/getpwuid.c \
	bionic/signalfd.c

# The following files are common, but must be compiled
# with different C flags when building a static C library.
#
# The reason for this is the implementation of __get_tls()
# that will differ between the shared and static versions
# of the library.
#
# See comments in private/bionic_tls.h for more details.
#
# NOTE: bionic/pthread.c is added later to this list
#       because it needs special handling on ARM, see
#       below.
#
libc_static_common_src_files = \
        unistd/sysconf.c \
        bionic/__errno.c

# Architecture specific source files go here
# =========================================================
if TARGET_ARCH_IS_ARM

# FIXME: need to do something about the .c.arm situation

libc_common_src_files += \
	bionic/bionic_clone.c \
	arch-arm/bionic/__get_pc.S \
	arch-arm/bionic/__get_sp.S \
	arch-arm/bionic/_exit_with_stack_teardown.S \
	arch-arm/bionic/_setjmp.S \
	arch-arm/bionic/clone.S \
	arch-arm/bionic/eabi.c \
	arch-arm/bionic/ffs.S \
	arch-arm/bionic/futex_arm.S \
	arch-arm/bionic/kill.S \
	arch-arm/bionic/libgcc_compat.c \
	arch-arm/bionic/tkill.S \
	arch-arm/bionic/tgkill.S \
	arch-arm/bionic/setjmp.S \
	arch-arm/bionic/sigsetjmp.S \
	arch-arm/bionic/strlen.c \
	arch-arm/bionic/syscall.c \
	arch-arm/bionic/__syscall.S \
	string/memmove.c \
	string/bcopy.c \
	string/strncmp.c \
	unistd/socketcalls.c

## 20150504@CF: removing this for now - it doesn't seem to be used
# 	arch-arm/bionic/atomics_arm.c

## 20150430@CF: disabling these for the time being
#	arch-arm/bionic/memcmp.S
#	arch-arm/bionic/memcmp16.S
#	arch-arm/bionic/memcpy.S
#	arch-arm/bionic/memset.S
libc_common_src_files += \
	string/memcmp.c \
	string/memcpy.c \
	string/memset.c

## 20150501@CF: disabling these for the time being
#	arch-arm/bionic/strcpy.S
#	arch-arm/bionic/strcmp.S
libc_common_src_files += \
	string/strcpy.c \
	string/strcmp.c

# These files need to be arm so that gdbserver
# can set breakpoints in them without messing
# up any thumb code.
libc_common_src_files += \
	bionic/pthread-atfork.c \
	bionic/pthread-rwlocks.c \
	bionic/pthread-timers.c \
	bionic/ptrace.c

libc_static_common_src_files += \
        bionic/pthread.c

# these are used by the static and dynamic versions of the libc
# respectively
libc_arch_static_src_files = \
	arch-arm/bionic/exidx_static.c

libc_arch_dynamic_src_files = \
	arch-arm/bionic/exidx_dynamic.c
else # !arm

if TARGET_ARCH_IS_X86
libc_common_src_files += \
	arch-x86/bionic/__get_sp.S \
	arch-x86/bionic/__get_tls.c \
	arch-x86/bionic/__set_tls.c \
	arch-x86/bionic/clone.S \
	arch-x86/bionic/_exit_with_stack_teardown.S \
	arch-x86/bionic/futex_x86.S \
	arch-x86/bionic/setjmp.S \
	arch-x86/bionic/_setjmp.S \
	arch-x86/bionic/sigsetjmp.S \
	arch-x86/bionic/vfork.S \
	arch-x86/bionic/syscall.S \
	arch-x86/string/bcopy_wrapper.S \
	arch-x86/string/memcpy_wrapper.S \
	arch-x86/string/memmove_wrapper.S \
	arch-x86/string/bzero_wrapper.S \
	arch-x86/string/memcmp_wrapper.S \
	arch-x86/string/memset_wrapper.S \
	arch-x86/string/strcmp_wrapper.S \
	arch-x86/string/strncmp_wrapper.S \
	arch-x86/string/strlen_wrapper.S \
	string/strcpy.c \
	bionic/pthread-atfork.c \
	bionic/pthread-rwlocks.c \
	bionic/pthread-timers.c \
	bionic/ptrace.c

# These files are to wean bionic off libgcc

libc_common_src_files += \
	arch-x86/bionic/__divdi3.S \
	arch-x86/bionic/__moddi3.S \
	arch-x86/bionic/__popcountsi2.c \
	arch-x86/bionic/__udivdi3.S \
	arch-x86/bionic/__umoddi3.S

#	arch-x86/bionic/__deregister_frame_info_bases.c \
#	arch-x86/bionic/__register_frame_info_bases.c

libc_static_common_src_files += \
        bionic/pthread.c

# this is needed for static versions of libc
libc_arch_static_src_files = \
	arch-x86/bionic/dl_iterate_phdr_static.c

libc_arch_dynamic_src_files =
else # !x86

endif # !x86
endif # !arm

# Define some common cflags
# ========================================================

common_cppflags = @COMMON_CFLAGS@

libc_common_cflags = $(common_cppflags)

libc_common_cflags += \
		-DBIONIC_DATADIR=\"$(BIONIC_DATADIR)\" \
		-DWITH_ERRLIST			\
		-DUSE_LOCKS 			\
		-DREALLOC_ZERO_BYTES_FREES 	\
		-D_LIBC=1 			\
		-DSOFTFLOAT                     \
		-DFLOATING_POINT		\
		-DINET6 \
		-I$(top_srcdir)/libc \
		-I$(top_srcdir)/libc/private \
		-DPOSIX_MISTAKE

# these macro definitions are required to implement the
# 'timezone' and 'daylight' global variables, as well as
# properly update the 'tm_gmtoff' field in 'struct tm'.
#
libc_common_cflags += \
    -DTM_GMTOFF=tm_gmtoff \
    -DUSG_COMPAT=1

if TARGET_ARCH_IS_ARM
  libc_common_cflags += -fstrict-aliasing
  libc_crt_target_cflags += -mthumb-interwork
  #
  # Define HAVE_ARM_TLS_REGISTER macro to indicate to the C library
  # that it should access the hardware TLS register directly in
  # private/bionic_tls.h
  #
  # The value must match your kernel configuration
  #
if ARCH_ARM_HAVE_TLS_REGISTER
    libc_common_cflags += -DHAVE_ARM_TLS_REGISTER
endif
if ! ARCH_ARM_HAVE_NEON
    libc_common_cflags += -DARCH_ARM_USE_NON_NEON_MEMCPY
endif
endif

if TARGET_ARCH_IS_X86
if ARCH_X86_HAVE_SSE2
    libc_crt_target_cflags += -DUSE_SSE2=1
endif
if ARCH_X86_HAVE_SSSE3
    libc_crt_target_cflags += -DUSE_SSSE3=1
endif
endif # x86

# Define some common includes
# ========================================================
libc_common_c_includes = \
		$(top_srcdir)/libc/include  \
		$(top_builddir)/libc/include  \
		$(top_srcdir)/libc/stdlib  \
		$(top_srcdir)/libc/string  \
		$(top_srcdir)/libc/stdio   \
		$(top_srcdir)/libm/include

# To enable malloc leak check for statically linked programs, add
# "WITH_MALLOC_CHECK_LIBC_A = true" to buildspec.mk
#WITH_MALLOC_CHECK_LIBC_A = $(strip $(WITH_MALLOC_CHECK_LIBC_A))

# ========================================================
# libc_common.a
# ========================================================

# XXX: this seems to be the only way to include generated sources reliably
libc_common_gen_files =
$(top_builddir)/libc/libc_generated_sources.mk: $(SYSCALLS_STAMP)
	mkdir -p $(dir $@)
	cat $< | sed -e 's|\(.*\)|libc_common_gen_files\ +=\ \1|g' > $@
-include $(top_builddir)/libc/libc_generated_sources.mk

libc_common_dep = $(top_builddir)/libc_generated_sources.mk
libc_common_src = $(addprefix $(top_srcdir)/libc/,$(libc_common_src_files)) $(addprefix $(top_builddir)/,$(libc_common_gen_files))
libc_common_obj =
if TARGET_ARCH_IS_ARM
libc_common_cflags += -DCRT_LEGACY_WORKAROUND
endif
libc_common_cflags += $(addprefix -I,$(libc_common_c_includes))

#define dep-one-file
#$(1): $(2)
#endef

#$(foreach f,$(libc_common_src), $(eval $(call dep-one-file,$(f),$(SYSCALLS_STAMP))))
$(foreach f,$(libc_common_src), $(eval $(call compile-one-file,$(f),libc_common,$(libc_common_dep))))

$(top_builddir)/libc/libc_common.a: $(libc_common_obj) $(SYSCALLS_STAMP) 
	mkdir -p $(dir $@)
	rm -f $@
	@AR@ crsP $@ $(libc_common_obj)

# ========================================================
# libc_nomalloc.a
# ========================================================
#
# This is a version of the static C library that does not
# include malloc. It's useful in situations when calling
# the user wants to provide their own malloc implementation,
# or wants to explicitly disallow the use of the use of malloc,
# like the dynamic loader.

libc_nomalloc_src_files = $(libc_arch_static_src_files) $(libc_static_common_src_files) bionic/libc_init_static.c

libc_nomalloc_cflags = $(libc_common_cflags) -DLIBC_STATIC

libc_nomalloc_src = $(addprefix $(top_srcdir)/libc/,$(libc_nomalloc_src_files))
libc_nomalloc_obj =
libc_nomalloc_dep = $(SYSCALLS_STAMP)
$(foreach f,$(libc_nomalloc_src), $(eval $(call compile-one-file,$(f),libc_nomalloc,$(libc_nomalloc_dep))))

$(eval libc_nomalloc_obj += $(libc_common_obj)) 

$(top_builddir)/libc/libc_nomalloc.a: $(libc_nomalloc_obj) $(SYSCALLS_STAMP) 
	mkdir -p $(dir $@)
	rm -f $@
	@AR@ crsP $@ $(libc_nomalloc_obj)

# ========================================================
# libc.a
# ========================================================

libc_static_src_files = \
	bionic/dlmalloc.c

libc_static_src = $(addprefix $(top_srcdir)/libc/,$(libc_static_src_files))
libc_static_obj =
libc_static_cflags = $(libc_common_cflags) -DLIBC_STATIC
libc_static_dep = $(SYSCALLS_STAMP)

$(foreach f,$(libc_static_src), $(eval $(call compile-one-file,$(f),libc_static,$(libc_static_dep))))

$(eval libc_static_obj += $(libc_nomalloc_obj))

$(top_builddir)/libc/libc.a: $(libc_static_obj) $(SYSCALLS_STAMP) 
	mkdir -p $(dir $@)
	rm -f $@
	@AR@ crsP $@ $(libc_static_obj)

# ========================================================
# libc.so
# ========================================================

libc_dynamic_src_files = \
	bionic/dlmalloc.c \
	unistd/sysconf.c \
	bionic/__errno.c \
	bionic/pthread.c \
	bionic/libc_init_dynamic.c

libc_dynamic_src = $(addprefix $(top_srcdir)/libc/,$(libc_dynamic_src_files))
libc_dymamic_dep = $(libc_common_dep) $(SYSCALLS_STAMP) $(CRTFILES) libdl-all
libc_dynamic_obj =
libc_dynamic_cflags = $(libc_common_cflags)
if PTHREAD_DEBUG
libc_dynamic_cflags += -DPTHREAD_DEBUG -DPTHREAD_DEBUG_ENABLED=1
else
libc_dynamic_cflags += -DPTHREAD_DEBUG -DPTHREAD_DEBUG_ENABLED=0
endif
libc_dynamic_cflags += $(addprefix -I,$(libc_common_c_includes))
libc_ldflags = @COMMON_LDFLAGS@
libc_ldflags += -Bsymbolic -shared -Wl,-soname,libc.so
libc_ldlibs = @COMMON_LDLIBS@ -ldl

$(foreach f,$(libc_dynamic_src), $(eval $(call compile-one-file,$(f),libc_dynamic,$(libc_dynamic_dep))))

$(top_builddir)/libc/libc.so: $(libc_dynamic_obj) $(top_builddir)/libc/libc_common.a
	@CC@ $(libc_ldflags) -o $@ $(CRTBEGIN_SO) $(libc_dynamic_obj) -Wl,--whole-archive $(top_builddir)/libc/libc_common.a -Wl,--no-whole-archive $(libc_ldlibs) $(CRTEND_SO)

# ========================================================
# common targets
# ========================================================

libc-all: \
  $(top_builddir)/libc/libc_common.a \
  $(top_builddir)/libc/libc_nomalloc.a \
  $(top_builddir)/libc/libc.a \
  $(top_builddir)/libc/libc.so

libc-clean:
	rm -f \
		$(top_builddir)/libc/libc_common.a \
		$(top_builddir)/libc/libc_nomalloc.a \
		$(libc_static_obj) $(top_builddir)/libc/libc.a \
		$(libc_dynamic_obj) $(top_builddir)/libc/libc.so \
		$(top_builddir)/libc/libc_generated_sources.mk \
		$(libc_dynamic_src_files)

# /lib is the standard place for C shared libraries, so create a symlink to that in /usr/lib
libc-install-exec-local: libc-all
	$(INSTALL) -m 644 -D $(top_builddir)/libc/libc.a $(DESTDIR)$(libdir)/libc.a
	$(INSTALL) -m 644 -D $(top_builddir)/libc/libc.so $(DESTDIR)$(libdir)/libc.so
	if [ "$(libdir)" != "/lib" ]; then \
		$(INSTALL) -d $(DESTDIR)/lib && \
		cd $(DESTDIR)/lib && \
		ln -sf $(libdir)/libc.so .; \
	fi

if ! HEADERS_ONLY

libcdir   = $(BIONIC_DATADIR)/libc
libc_DATA = \
	$(addprefix libc/, \
		MODULE_LICENSE_BSD \
		NOTICE \
		README \
		CAVEATS \
	)
# the following is mainly for historical purposes
libc_DATA += \
	$(addprefix libc/docs/, \
		CHANGES.TXT \
		ISSUES.TXT \
		OVERVIEW.TXT \
		SYSV-IPC.TXT \
	)

libckerneldir   = $(BIONIC_DATADIR)/libc/kernel
libckernel_DATA = \
	$(addprefix libc/kernel/, \
		README.TXT \
		$(addprefix tools/, \
			clean_header.py \
			cpp.py \
			defaults.py \
			find_headers.py \
			find_users.py \
			kernel.py \
			update_all.py \
			utils.py \
		) \
	)

endif

ALL_LOCAL += libc-all
CLEAN_LOCAL += libc-clean
INSTALL_EXEC_LOCAL += libc-install-exec-local
