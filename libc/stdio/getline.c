#include <stdio.h>

ssize_t getline(char **lineptr, size_t *n, FILE *stream) {
    return getdelim(lineptr,n,(int)'\n',stream);
}
