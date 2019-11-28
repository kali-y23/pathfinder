#include "libmx.h"

void *mx_memchr(const void *s, int c, size_t n) {
    int index = mx_get_charn_index((char *) s, c, n);
    char *tmp = (char *) s;
    char *res = (index == -1) ? NULL : &tmp[index];
    return (void *) res;
}
