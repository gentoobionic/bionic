#include <sys/types.h>

#include "stub.h"

int mbtowc(wchar_t *pwc, const char *s, size_t n) __attribute__ ((weak));
int mbtowc(wchar_t *pwc, const char *s, size_t n) {
    BIONICSTUB();
    return -1;
}

char *nl_langinfo(void *item) __attribute__ ((weak));
char *nl_langinfo(void *item) {
    BIONICSTUB();
    return "US-ASCII";
}

int wctomb(char *s, wchar_t wc) __attribute__ ((weak));
int wctomb(char *s, wchar_t wc) {
    BIONICSTUB();
    return -1;
}

int mblen(const char *s, size_t n) __attribute__ ((weak));
int mblen(const char *s, size_t n) {
    BIONICSTUB();
    return -1;
}
