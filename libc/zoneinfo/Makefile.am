zoneinfodir   = $(datadir)/zoneinfo
zoneinfo_DATA = \
	$(addprefix libc/zoneinfo/, \
		zoneinfo.dat \
		zoneinfo.idx \
		zoneinfo.version \
	)

zoneinfotoolsdir   = $(BIONIC_DATADIR)/zoneinfo
zoneinfotools_DATA = \
	$(addprefix libc/tools/zoneinfo/, \
		generate \
		ZoneCompactor.java \
		ZoneInfo.java \
	) \
	$(addprefix libc/zoneinfo/, \
		MODULE_LICENSE_PUBLIC_DOMAIN \
	)

# TODO: make a sysconfdir variable / define, edit libc/tzcode/tzfile.h and so on instead of hard-coding TZDIR="/etc"
# also need to figure out how to make the timezones behave like the glibc variant
#
# e.g. cd /etc; rm -f localtime; ln -sf ../usr/share/zoneinfo/Canada/Eastern localtime
#
# If localtime could acknowledge that /etc/localtime might be a link, and read the value of the link, then
# it would be possible to use the symbolic link data path instead of file content for the timezone.