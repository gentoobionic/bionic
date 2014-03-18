libthread_db_cflags = @COMMON_CFLAGS@
libthread_db_ldflags = $(subst -Wl$(COMMA)-no-undefined,,@COMMON_LDFLAGS@)
libthread_db_ldflags += -Bsymbolic -shared -Wl,-soname,libthread_db.so
libthread_db_ldlibs = -lc -ldl

libthread_db_src_files = libthread_db/libthread_db.c

libthread_db_src = $(addprefix $(top_srcdir)/,$(libthread_db_src_files))
libthread_db_obj = 
libthread_db_dep = $(CRTFILES) libc-all libdl-all

$(foreach f,$(libthread_db_src), $(eval $(call compile-one-file,$(f),libthread_db,$(libthread_db_dep))))

.PHONY: libthread_db-all-local libthread_db-clean-local libthread_db-install-exec-local

$(top_builddir)/libthread_db/libthread_db.a: $(libthread_db_obj)
	mkdir -p $(dir $@)
	@AR@ crsP $@ $^

$(top_builddir)/libthread_db/libthread_db.so: $(libthread_db_obj) $(libthread_db_dep)
	mkdir -p $(dir $@)
	@CC@ $(libthread_db_ldflags) -o $@ $(CRTBEGIN_SO) $(libthread_db_obj) $(libthread_db_ldlibs) $(CRTEND_SO)

libthread_db-all: $(top_builddir)/libthread_db/libthread_db.a $(top_builddir)/libthread_db/libthread_db.so

libthread_db-clean:
	rm -f $(libthread_db_obj) $(top_builddir)/libthread_db/libthread_db.a $(top_builddir)/libthread_db/libthread_db.so

# /lib is the standard place for C shared libraries, so create a symlink to that in /usr/lib
libthread_db-install-exec-local: libthread_db-all
	$(INSTALL) -m 644 -D $(top_builddir)/libthread_db/libthread_db.a $(DESTDIR)$(libdir)/libthread_db.a
	$(INSTALL) -m 644 -D $(top_builddir)/libthread_db/libthread_db.so $(DESTDIR)$(libdir)/libthread_db.so
	if [ "$(libdir)" != "/lib" ]; then \
		$(INSTALL) -d $(DESTDIR)/lib && \
		cd $(DESTDIR)/lib && \
		ln -sf $(libdir)/libthread_db.so .; \
	fi

if ! HEADERS_ONLY

libthreaddbdir   = $(BIONIC_DATADIR)/libthread_db
libthreaddb_DATA = \
	$(addprefix libthread_db/, \
		MODULE_LICENSE_BSD \
		NOTICE \
	)

endif

ALL_LOCAL += libthread_db-all
CLEAN_LOCAL += libthread_db-clean
INSTALL_EXEC_LOCAL += libthread_db-install-exec-local
