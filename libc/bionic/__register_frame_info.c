struct object {
	int x;
};

void __register_frame_info_bases(const void *begin, struct object *ob, void *tbase, void *dbase) __attribute__((weak));
void __register_frame_info_bases(const void *begin, struct object *ob, void *tbase, void *dbase) {
	// FIXME: implement this function
	/*
	 * I don't want to have to rely on an external library for frame unwinding and exception support, except for maybe libunwind, since it is X11 / BSD / Nvidia(??) licensed.
	 * In libgcc, this is really just an abstraction layer to libunwind anyway.
	 */
}

void *__deregister_frame_info_bases (const void *begin) __attribute__((weak));
void *__deregister_frame_info_bases (const void *begin) {
	// FIXME: implement this function
	return 0;
}
