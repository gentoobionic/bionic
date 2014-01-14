SUBDIRS = zoneinfo

BUILT_SOURCES =

libc_crt_target_cflags =

lib_LTLIBRARIES = libc_common.la libc.la libc_static.la

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
	bionic/logd_write.c \
	bionic/md5.c \
	bionic/memmove_words.c \
	bionic/pututline.c \
	bionic/realpath.c \
	bionic/sched_getaffinity.c \
	bionic/sched_getcpu.c \
	bionic/sched_cpualloc.c \
	bionic/sched_cpucount.c \
	bionic/semaphore.c \
	bionic/sha1.c \
	bionic/ssp.c \
	bionic/system_properties.c \
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
	pwd/getpwuid.c

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
libc_common_src_files += \
	bionic/bionic_clone.c \
	arch-arm/bionic/__get_pc.S \
	arch-arm/bionic/__get_sp.S \
	arch-arm/bionic/_exit_with_stack_teardown.S \
	arch-arm/bionic/_setjmp.S \
	arch-arm/bionic/abort_arm.S \
	arch-arm/bionic/atomics_arm.c \
	arch-arm/bionic/clone.S \
	arch-arm/bionic/eabi.c \
	arch-arm/bionic/ffs.S \
	arch-arm/bionic/futex_arm.S \
	arch-arm/bionic/kill.S \
	arch-arm/bionic/libgcc_compat.c \
	arch-arm/bionic/tkill.S \
	arch-arm/bionic/tgkill.S \
	arch-arm/bionic/memcmp.S \
	arch-arm/bionic/memcmp16.S \
	arch-arm/bionic/memcpy.S \
	arch-arm/bionic/memset.S \
	arch-arm/bionic/setjmp.S \
	arch-arm/bionic/sigsetjmp.S \
	arch-arm/bionic/strlen.c.arm \
	arch-arm/bionic/strcpy.S \
	arch-arm/bionic/strcmp.S \
	arch-arm/bionic/syscall.S \
	string/memmove.c.arm \
	string/bcopy.c \
	string/strncmp.c \
	unistd/socketcalls.c

libc_common_src_files += arch-arm/syscalls/__brk.S arch-arm/syscalls/__fcntl.S arch-arm/syscalls/__fcntl64.S arch-arm/syscalls/__fork.S arch-arm/syscalls/__fstatfs64.S arch-arm/syscalls/__getcpu.S arch-arm/syscalls/__getcwd.S arch-arm/syscalls/__getpriority.S arch-arm/syscalls/__ioctl.S arch-arm/syscalls/__llseek.S arch-arm/syscalls/__mmap2.S arch-arm/syscalls/__open.S arch-arm/syscalls/__openat.S arch-arm/syscalls/__ptrace.S arch-arm/syscalls/__reboot.S arch-arm/syscalls/__rt_sigaction.S arch-arm/syscalls/__rt_sigprocmask.S arch-arm/syscalls/__rt_sigtimedwait.S arch-arm/syscalls/__sched_getaffinity.S arch-arm/syscalls/__set_tls.S arch-arm/syscalls/__setresuid.S arch-arm/syscalls/__setreuid.S arch-arm/syscalls/__setuid.S arch-arm/syscalls/__sigsuspend.S arch-arm/syscalls/__statfs64.S arch-arm/syscalls/__sys_clone.S arch-arm/syscalls/__syslog.S arch-arm/syscalls/__timer_create.S arch-arm/syscalls/__timer_delete.S arch-arm/syscalls/__timer_getoverrun.S arch-arm/syscalls/__timer_gettime.S arch-arm/syscalls/__timer_settime.S arch-arm/syscalls/__wait4.S arch-arm/syscalls/__waitid.S arch-arm/syscalls/_exit.S arch-arm/syscalls/_exit_thread.S arch-arm/syscalls/accept.S arch-arm/syscalls/access.S arch-arm/syscalls/acct.S arch-arm/syscalls/adjtimex.S arch-arm/syscalls/bind.S arch-arm/syscalls/cacheflush.S arch-arm/syscalls/capget.S arch-arm/syscalls/capset.S arch-arm/syscalls/chdir.S arch-arm/syscalls/chmod.S arch-arm/syscalls/chown.S arch-arm/syscalls/chroot.S arch-arm/syscalls/clock_getres.S arch-arm/syscalls/clock_gettime.S arch-arm/syscalls/clock_nanosleep.S arch-arm/syscalls/clock_settime.S arch-arm/syscalls/close.S arch-arm/syscalls/connect.S arch-arm/syscalls/delete_module.S arch-arm/syscalls/dup.S arch-arm/syscalls/dup2.S arch-arm/syscalls/epoll_create.S arch-arm/syscalls/epoll_ctl.S arch-arm/syscalls/epoll_wait.S arch-arm/syscalls/eventfd.S arch-arm/syscalls/execve.S arch-arm/syscalls/faccessat.S arch-arm/syscalls/fchdir.S arch-arm/syscalls/fchmod.S arch-arm/syscalls/fchmodat.S arch-arm/syscalls/fchown.S arch-arm/syscalls/fchownat.S arch-arm/syscalls/fdatasync.S arch-arm/syscalls/fgetxattr.S arch-arm/syscalls/flistxattr.S arch-arm/syscalls/flock.S arch-arm/syscalls/fremovexattr.S arch-arm/syscalls/fsetxattr.S arch-arm/syscalls/fstat.S arch-arm/syscalls/fstatat.S arch-arm/syscalls/fsync.S arch-arm/syscalls/ftruncate.S arch-arm/syscalls/ftruncate64.S arch-arm/syscalls/futex.S arch-arm/syscalls/getdents.S arch-arm/syscalls/getegid.S arch-arm/syscalls/geteuid.S arch-arm/syscalls/getgid.S arch-arm/syscalls/getgroups.S arch-arm/syscalls/getitimer.S arch-arm/syscalls/getpeername.S arch-arm/syscalls/getpgid.S arch-arm/syscalls/getpid.S arch-arm/syscalls/getppid.S arch-arm/syscalls/getresgid.S arch-arm/syscalls/getresuid.S arch-arm/syscalls/getrlimit.S arch-arm/syscalls/getrusage.S arch-arm/syscalls/getsid.S arch-arm/syscalls/getsockname.S arch-arm/syscalls/getsockopt.S arch-arm/syscalls/gettid.S arch-arm/syscalls/gettimeofday.S arch-arm/syscalls/getuid.S arch-arm/syscalls/getxattr.S arch-arm/syscalls/init_module.S arch-arm/syscalls/inotify_add_watch.S arch-arm/syscalls/inotify_init.S arch-arm/syscalls/inotify_rm_watch.S arch-arm/syscalls/ioprio_get.S arch-arm/syscalls/ioprio_set.S arch-arm/syscalls/klogctl.S arch-arm/syscalls/lchown.S arch-arm/syscalls/lgetxattr.S arch-arm/syscalls/link.S arch-arm/syscalls/listen.S arch-arm/syscalls/listxattr.S arch-arm/syscalls/llistxattr.S arch-arm/syscalls/lremovexattr.S arch-arm/syscalls/lseek.S arch-arm/syscalls/lsetxattr.S arch-arm/syscalls/lstat.S arch-arm/syscalls/madvise.S arch-arm/syscalls/mincore.S arch-arm/syscalls/mkdir.S arch-arm/syscalls/mkdirat.S arch-arm/syscalls/mknod.S arch-arm/syscalls/mlock.S arch-arm/syscalls/mount.S arch-arm/syscalls/mprotect.S arch-arm/syscalls/mremap.S arch-arm/syscalls/msgctl.S arch-arm/syscalls/msgget.S arch-arm/syscalls/msync.S arch-arm/syscalls/munlock.S arch-arm/syscalls/munmap.S arch-arm/syscalls/nanosleep.S arch-arm/syscalls/pause.S arch-arm/syscalls/perf_event_open.S arch-arm/syscalls/personality.S arch-arm/syscalls/pipe.S arch-arm/syscalls/pipe2.S arch-arm/syscalls/pivot_root.S arch-arm/syscalls/poll.S arch-arm/syscalls/prctl.S arch-arm/syscalls/pread64.S arch-arm/syscalls/pwrite64.S arch-arm/syscalls/read.S arch-arm/syscalls/readahead.S arch-arm/syscalls/readlink.S arch-arm/syscalls/readv.S arch-arm/syscalls/recvfrom.S arch-arm/syscalls/recvmsg.S arch-arm/syscalls/removexattr.S arch-arm/syscalls/rename.S arch-arm/syscalls/renameat.S arch-arm/syscalls/rmdir.S arch-arm/syscalls/sched_get_priority_max.S arch-arm/syscalls/sched_get_priority_min.S arch-arm/syscalls/sched_getparam.S arch-arm/syscalls/sched_getscheduler.S arch-arm/syscalls/sched_rr_get_interval.S arch-arm/syscalls/sched_setaffinity.S arch-arm/syscalls/sched_setparam.S arch-arm/syscalls/sched_setscheduler.S arch-arm/syscalls/sched_yield.S arch-arm/syscalls/select.S arch-arm/syscalls/semctl.S arch-arm/syscalls/semget.S arch-arm/syscalls/semop.S arch-arm/syscalls/sendfile.S arch-arm/syscalls/sendmsg.S arch-arm/syscalls/sendto.S arch-arm/syscalls/setgid.S arch-arm/syscalls/setgroups.S arch-arm/syscalls/sethostname.S arch-arm/syscalls/setitimer.S arch-arm/syscalls/setpgid.S arch-arm/syscalls/setpriority.S arch-arm/syscalls/setregid.S arch-arm/syscalls/setresgid.S arch-arm/syscalls/setrlimit.S arch-arm/syscalls/setsid.S arch-arm/syscalls/setsockopt.S arch-arm/syscalls/settimeofday.S arch-arm/syscalls/setxattr.S arch-arm/syscalls/shmat.S arch-arm/syscalls/shmctl.S arch-arm/syscalls/shmdt.S arch-arm/syscalls/shmget.S arch-arm/syscalls/shutdown.S arch-arm/syscalls/sigaction.S arch-arm/syscalls/sigaltstack.S arch-arm/syscalls/sigpending.S arch-arm/syscalls/sigprocmask.S arch-arm/syscalls/socket.S arch-arm/syscalls/socketpair.S arch-arm/syscalls/stat.S arch-arm/syscalls/stime.S arch-arm/syscalls/swapoff.S arch-arm/syscalls/swapon.S arch-arm/syscalls/symlink.S arch-arm/syscalls/sync.S arch-arm/syscalls/sysinfo.S arch-arm/syscalls/times.S arch-arm/syscalls/truncate.S arch-arm/syscalls/umask.S arch-arm/syscalls/umount2.S arch-arm/syscalls/uname.S arch-arm/syscalls/unlink.S arch-arm/syscalls/unlinkat.S arch-arm/syscalls/utimensat.S arch-arm/syscalls/utimes.S arch-arm/syscalls/vfork.S arch-arm/syscalls/write.S arch-arm/syscalls/writev.S

# These files need to be arm so that gdbserver
# can set breakpoints in them without messing
# up any thumb code.
libc_common_src_files += \
	bionic/pthread-atfork.c.arm \
	bionic/pthread-rwlocks.c.arm \
	bionic/pthread-timers.c.arm \
	bionic/ptrace.c.arm

libc_static_common_src_files += \
        bionic/pthread.c.arm

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

libc_common_src_files += arch-x86/syscalls/__brk.S arch-x86/syscalls/__fcntl.S arch-x86/syscalls/__fcntl64.S arch-x86/syscalls/__fork.S arch-x86/syscalls/__fstatfs64.S arch-x86/syscalls/__getcpu.S arch-x86/syscalls/__getcwd.S arch-x86/syscalls/__getpriority.S arch-x86/syscalls/__ioctl.S arch-x86/syscalls/__llseek.S arch-x86/syscalls/__mmap2.S arch-x86/syscalls/__open.S arch-x86/syscalls/__openat.S arch-x86/syscalls/__ptrace.S arch-x86/syscalls/__reboot.S arch-x86/syscalls/__rt_sigaction.S arch-x86/syscalls/__rt_sigprocmask.S arch-x86/syscalls/__rt_sigtimedwait.S arch-x86/syscalls/__sched_getaffinity.S arch-x86/syscalls/__set_thread_area.S arch-x86/syscalls/__setresuid.S arch-x86/syscalls/__setreuid.S arch-x86/syscalls/__setuid.S arch-x86/syscalls/__sigsuspend.S arch-x86/syscalls/__statfs64.S arch-x86/syscalls/__sys_clone.S arch-x86/syscalls/__syslog.S arch-x86/syscalls/__timer_create.S arch-x86/syscalls/__timer_delete.S arch-x86/syscalls/__timer_getoverrun.S arch-x86/syscalls/__timer_gettime.S arch-x86/syscalls/__timer_settime.S arch-x86/syscalls/__wait4.S arch-x86/syscalls/__waitid.S arch-x86/syscalls/_exit.S arch-x86/syscalls/_exit_thread.S arch-x86/syscalls/_waitpid.S arch-x86/syscalls/accept.S arch-x86/syscalls/access.S arch-x86/syscalls/acct.S arch-x86/syscalls/adjtimex.S arch-x86/syscalls/bind.S arch-x86/syscalls/capget.S arch-x86/syscalls/capset.S arch-x86/syscalls/chdir.S arch-x86/syscalls/chmod.S arch-x86/syscalls/chown.S arch-x86/syscalls/chroot.S arch-x86/syscalls/clock_getres.S arch-x86/syscalls/clock_gettime.S arch-x86/syscalls/clock_nanosleep.S arch-x86/syscalls/clock_settime.S arch-x86/syscalls/close.S arch-x86/syscalls/connect.S arch-x86/syscalls/delete_module.S arch-x86/syscalls/dup.S arch-x86/syscalls/dup2.S arch-x86/syscalls/epoll_create.S arch-x86/syscalls/epoll_ctl.S arch-x86/syscalls/epoll_wait.S arch-x86/syscalls/eventfd.S arch-x86/syscalls/execve.S arch-x86/syscalls/faccessat.S arch-x86/syscalls/fchdir.S arch-x86/syscalls/fchmod.S arch-x86/syscalls/fchmodat.S arch-x86/syscalls/fchown.S arch-x86/syscalls/fchownat.S arch-x86/syscalls/fdatasync.S arch-x86/syscalls/fgetxattr.S arch-x86/syscalls/flistxattr.S arch-x86/syscalls/flock.S arch-x86/syscalls/fremovexattr.S arch-x86/syscalls/fsetxattr.S arch-x86/syscalls/fstat.S arch-x86/syscalls/fstatat.S arch-x86/syscalls/fsync.S arch-x86/syscalls/ftruncate.S arch-x86/syscalls/ftruncate64.S arch-x86/syscalls/futex.S arch-x86/syscalls/getdents.S arch-x86/syscalls/getegid.S arch-x86/syscalls/geteuid.S arch-x86/syscalls/getgid.S arch-x86/syscalls/getgroups.S arch-x86/syscalls/getitimer.S arch-x86/syscalls/getpeername.S arch-x86/syscalls/getpgid.S arch-x86/syscalls/getpid.S arch-x86/syscalls/getppid.S arch-x86/syscalls/getresgid.S arch-x86/syscalls/getresuid.S arch-x86/syscalls/getrlimit.S arch-x86/syscalls/getrusage.S arch-x86/syscalls/getsid.S arch-x86/syscalls/getsockname.S arch-x86/syscalls/getsockopt.S arch-x86/syscalls/gettid.S arch-x86/syscalls/gettimeofday.S arch-x86/syscalls/getuid.S arch-x86/syscalls/getxattr.S arch-x86/syscalls/init_module.S arch-x86/syscalls/inotify_add_watch.S arch-x86/syscalls/inotify_init.S arch-x86/syscalls/inotify_rm_watch.S arch-x86/syscalls/ioprio_get.S arch-x86/syscalls/ioprio_set.S arch-x86/syscalls/kill.S arch-x86/syscalls/klogctl.S arch-x86/syscalls/lchown.S arch-x86/syscalls/lgetxattr.S arch-x86/syscalls/link.S arch-x86/syscalls/listen.S arch-x86/syscalls/listxattr.S arch-x86/syscalls/llistxattr.S arch-x86/syscalls/lremovexattr.S arch-x86/syscalls/lseek.S arch-x86/syscalls/lsetxattr.S arch-x86/syscalls/lstat.S arch-x86/syscalls/madvise.S arch-x86/syscalls/mincore.S arch-x86/syscalls/mkdir.S arch-x86/syscalls/mkdirat.S arch-x86/syscalls/mknod.S arch-x86/syscalls/mlock.S arch-x86/syscalls/mount.S arch-x86/syscalls/mprotect.S arch-x86/syscalls/mremap.S arch-x86/syscalls/msgctl.S arch-x86/syscalls/msgget.S arch-x86/syscalls/msync.S arch-x86/syscalls/munlock.S arch-x86/syscalls/munmap.S arch-x86/syscalls/nanosleep.S arch-x86/syscalls/pause.S arch-x86/syscalls/perf_event_open.S arch-x86/syscalls/personality.S arch-x86/syscalls/pipe.S arch-x86/syscalls/pipe2.S arch-x86/syscalls/pivot_root.S arch-x86/syscalls/poll.S arch-x86/syscalls/prctl.S arch-x86/syscalls/pread64.S arch-x86/syscalls/pwrite64.S arch-x86/syscalls/read.S arch-x86/syscalls/readahead.S arch-x86/syscalls/readlink.S arch-x86/syscalls/readv.S arch-x86/syscalls/recvfrom.S arch-x86/syscalls/recvmsg.S arch-x86/syscalls/removexattr.S arch-x86/syscalls/rename.S arch-x86/syscalls/renameat.S arch-x86/syscalls/rmdir.S arch-x86/syscalls/sched_get_priority_max.S arch-x86/syscalls/sched_get_priority_min.S arch-x86/syscalls/sched_getparam.S arch-x86/syscalls/sched_getscheduler.S arch-x86/syscalls/sched_rr_get_interval.S arch-x86/syscalls/sched_setaffinity.S arch-x86/syscalls/sched_setparam.S arch-x86/syscalls/sched_setscheduler.S arch-x86/syscalls/sched_yield.S arch-x86/syscalls/select.S arch-x86/syscalls/semctl.S arch-x86/syscalls/semget.S arch-x86/syscalls/semop.S arch-x86/syscalls/sendfile.S arch-x86/syscalls/sendmsg.S arch-x86/syscalls/sendto.S arch-x86/syscalls/setgid.S arch-x86/syscalls/setgroups.S arch-x86/syscalls/sethostname.S arch-x86/syscalls/setitimer.S arch-x86/syscalls/setpgid.S arch-x86/syscalls/setpriority.S arch-x86/syscalls/setregid.S arch-x86/syscalls/setresgid.S arch-x86/syscalls/setrlimit.S arch-x86/syscalls/setsid.S arch-x86/syscalls/setsockopt.S arch-x86/syscalls/settimeofday.S arch-x86/syscalls/setxattr.S arch-x86/syscalls/shmat.S arch-x86/syscalls/shmctl.S arch-x86/syscalls/shmdt.S arch-x86/syscalls/shmget.S arch-x86/syscalls/shutdown.S arch-x86/syscalls/sigaction.S arch-x86/syscalls/sigaltstack.S arch-x86/syscalls/sigpending.S arch-x86/syscalls/sigprocmask.S arch-x86/syscalls/socket.S arch-x86/syscalls/socketpair.S arch-x86/syscalls/stat.S arch-x86/syscalls/stime.S arch-x86/syscalls/swapoff.S arch-x86/syscalls/swapon.S arch-x86/syscalls/symlink.S arch-x86/syscalls/sync.S arch-x86/syscalls/sysinfo.S arch-x86/syscalls/tgkill.S arch-x86/syscalls/times.S arch-x86/syscalls/tkill.S arch-x86/syscalls/truncate.S arch-x86/syscalls/umask.S arch-x86/syscalls/umount2.S arch-x86/syscalls/uname.S arch-x86/syscalls/unlink.S arch-x86/syscalls/unlinkat.S arch-x86/syscalls/utimensat.S arch-x86/syscalls/utimes.S arch-x86/syscalls/write.S arch-x86/syscalls/writev.S

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
libc_common_cflags = \
		-DWITH_ERRLIST			\
		-DANDROID_CHANGES		\
		-DUSE_LOCKS 			\
		-DREALLOC_ZERO_BYTES_FREES 	\
		-D_LIBC=1 			\
		-DSOFTFLOAT                     \
		-DFLOATING_POINT		\
		-DINET6 \
		-I$(top_srcdir)/libc \
		-I$(top_srcdir)/libc/private \
		-DUSE_DL_PREFIX \
		-DPOSIX_MISTAKE \
        -DLOG_ON_HEAP_ERROR

# these macro definitions are required to implement the
# 'timezone' and 'daylight' global variables, as well as
# properly update the 'tm_gmtoff' field in 'struct tm'.
#
libc_common_cflags += \
    -DTM_GMTOFF=tm_gmtoff \
    -DUSG_COMPAT=1

if DEBUG_BIONIC_LIBC
  libc_common_cflags += -DDEBUG
endif

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
if ARCH_ARM_USE_NON_NEON_MEMCPY
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

# Define ANDROID_SMP appropriately.
if TARGET_CPU_SMP
    libc_common_cflags += -DANDROID_SMP=1
else
    libc_common_cflags += -DANDROID_SMP=0
endif

# Needed to access private/__dso_handle.S from
# crtbegin_xxx.S and crtend_xxx.S
#
libc_crt_target_cflags += -I$(top_srcdir)/libc/private

if TARGET_ARCH_IS_ARM
libc_crt_target_cflags += -DCRT_LEGACY_WORKAROUND
endif

# Define some common includes
# ========================================================
libc_common_c_includes = \
		$(top_srcdir)/libc/stdlib  \
		$(top_srcdir)/libc/string  \
		$(top_srcdir)/libc/stdio

# Needed to access private/__dso_handle.S from
# crtbegin_xxx.S and crtend_xxx.S
# and machine/asm.h
#
libc_crt_target_cflags += -I$(top_srcdir)/libc/private -I$(top_srcdir)/libc/arch-$(TARGET_ARCH)/include

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

libc_crt_target_so_cflags = $(libc_crt_target_cflags)
if TARGET_ARCH_IS_X86
    # This flag must be added for x86 targets, but not for ARM
    libc_crt_target_so_cflags += -fPIC
endif
$(top_builddir)/crtbegin_so.o: $(top_srcdir)/libc/arch-$(TARGET_ARCH)/bionic/crtbegin_so.S
	@mkdir -p $(dir $@)
	@CC@ $(libc_crt_target_so_cflags) -o $@ -c $<
BUILT_SOURCES += $(top_builddir)/crtbegin_so.o

$(top_builddir)/crtend_so.o: $(top_srcdir)/libc/arch-$(TARGET_ARCH)/bionic/crtend_so.S
	@mkdir -p $(dir $@)
	@CC@ $(libc_crt_target_so_cflags) -o $@ -c $<
BUILT_SOURCES += $(top_builddir)/crtend_so.o
endif # TARGET_ARCH == x86 || TARGET_ARCH == arm


$(top_builddir)/crtbegin_static.o: $(top_srcdir)/libc/arch-$(TARGET_ARCH)/bionic/crtbegin_static.S
	@mkdir -p $(dir $@)
	@CC@ $(libc_crt_target_cflags) -o $@ -c $<
BUILT_SOURCES += $(top_builddir)/crtbegin_static.o

$(top_builddir)/crtbegin_dynamic.o: $(top_srcdir)/libc/arch-$(TARGET_ARCH)/bionic/crtbegin_dynamic.S
	@mkdir -p $(dir $@)
	@CC@ $(libc_crt_target_cflags) -o $@ -c $<
BUILT_SOURCES += $(top_builddir)/crtbegin_dynamic.o


# We rename crtend.o to crtend_android.o to avoid a
# name clash between gcc and bionic.
$(top_builddir)/crtend_android.o: $(top_srcdir)/libc/arch-$(TARGET_ARCH)/bionic/crtend.S
	@mkdir -p $(dir $@)
	@CC@ $(libc_crt_target_cflags) -o $@ -c $<
BUILT_SOURCES += $(top_builddir)/crtend_android.o


# To enable malloc leak check for statically linked programs, add
# "WITH_MALLOC_CHECK_LIBC_A = true" to buildspec.mk
#WITH_MALLOC_CHECK_LIBC_A = $(strip $(WITH_MALLOC_CHECK_LIBC_A))

# ========================================================
# libc_common.a
# ========================================================

libc_common_la_SOURCES = $(libc_common_src_files)
libc_common_la_CFLAGS = $(libc_common_cflags)
if TARGET_ARCH_IS_ARM
libc_common_la_CFLAGS += -DCRT_LEGACY_WORKAROUND
endif
libc_common_la_CPPFLAGS = $(addprefix -I,$(libc_common_c_includes))

# ========================================================
# libc.a
# ========================================================

libc_static_la_SOURCES = \
	$(libc_arch_static_src_files) \
	$(libc_static_common_src_files) \
	bionic/dlmalloc.c \
	bionic/malloc_debug_common.c \
	bionic/libc_init_static.c

libc_static_la_CFLAGS = $(libc_common_cflags) \
                -DLIBC_STATIC
libc_static_la_CPPFLAGS = $(addprefix -I,$(libc_common_c_includes))
libc_static_la_LIBADD = libc_common.la

# ========================================================
# libc.so
# ========================================================

# pthread deadlock prediction:
# set -DPTHREAD_DEBUG -DPTHREAD_DEBUG_ENABLED=1 to enable support for
# pthread deadlock prediction.
# Since this code is experimental it is disabled by default.
# see libc/bionic/pthread_debug.c for details

libc_la_CFLAGS = $(libc_common_cflags) -DPTHREAD_DEBUG -DPTHREAD_DEBUG_ENABLED=0

if TARGET_ARCH_IS_ARM
# TODO: At some point, we need to remove this custom linker script.
#libc_la_LDFLAGS = -Wl,-T,$(BUILD_SYSTEM)/armelf.xsc
endif

libc_la_CPPFLAGS = $(addprefix -I,$(libc_common_c_includes))

libc_la_SOURCES = \
	$(libc_arch_dynamic_src_files) \
	$(libc_static_common_src_files) \
	bionic/dlmalloc.c \
	bionic/malloc_debug_common.c \
	bionic/pthread_debug.c \
	bionic/libc_init_dynamic.c

# WARNING: The only library libc.so should depend on is libdl.so!  If you add other libraries,
# make sure to add -Wl,--exclude-libs=libgcc.a to the LOCAL_LDFLAGS for those libraries.  This
# ensures that symbols that are pulled into those new libraries from libgcc.a are not declared
# external; if that were the case, then libc would not pull those symbols from libgcc.a as it
# should, instead relying on the external symbols from the dependent libraries.  That would
# create an "cloaked" dependency on libgcc.a in libc though the libraries, which is not what
# you wanted!

libc_la_LIBADD = libc_common.la
libc_la_LDFLAGS = -lgcc

# For all builds, except for the -user build we will enable memory
# allocation checking (including memory leaks, buffer overwrites, etc.)
# Note that all these checks are also controlled by env. settings
# that can enable, or disable specific checks. Note also that some of
# the checks are available only in emulator and are implemeted in
# libc_malloc_qemu_instrumented.so.
#if 0

# ========================================================
# libc_malloc_debug_leak.so
# ========================================================

#LOCAL_CFLAGS = \
#	$(libc_common_cflags) \
#	-DMALLOC_LEAK_CHECK

#LOCAL_C_INCLUDES = $(libc_common_c_includes)

#LOCAL_SRC_FILES = \
#	bionic/malloc_debug_leak.c \
#	bionic/malloc_debug_check.c \
#	bionic/malloc_debug_check_mapinfo.c \
#	bionic/malloc_debug_stacktrace.c

#LOCAL_MODULE= libc_malloc_debug_leak

#LOCAL_SHARED_LIBRARIES = libc
#LOCAL_WHOLE_STATIC_LIBRARIES = libc_common
#LOCAL_SYSTEM_SHARED_LIBRARIES =
#LOCAL_ALLOW_UNDEFINED_SYMBOLS = true
