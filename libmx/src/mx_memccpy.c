#include "libmx.h"

void *mx_memccpy(void *restrict dst, const void *restrict src, int c, size_t n) {
    char *d = (char *) dst;
    char *s = (char *) src;
    size_t i = 0;
    
    while (i < n) {
        if (s[i] == c) {
            return &d[i + 1];
        }
        d[i] = s[i];
        i++;
    }
    return NULL;
}
