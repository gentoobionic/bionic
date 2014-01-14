# make a dummy libgcc_s.so so that __cxa_finalize@GLIBC2.13 isn't pulled in

$(top_builddir)/foo.c:
	echo "void __cxa_finalize(void) {}" > $@
	
$(top_builddir)/libgcc_s.so.1: $(top_builddir)/foo.c
	@CC@ -nodefaultlibs -static-libgcc -shared -Wl,-soname,libgcc_s.so.1 -o $(top_builddir)/libgcc_s.so.1 $(top_builddir)/foo.c

$(top_builddir)/libgcc_s.so: $(top_builddir)/libgcc_s.so.1
	cd $(top_builddir) && ln -sf $(notdir $<) $(notdir $@)
	
all: $(top_builddir)/libgcc_s.so

BUILT_SOURCES = $(top_builddir)/foo.c $(top_builddir)/libgcc_s.so.1

clean-local:
	rm -f $(BUILT_SOURCES)