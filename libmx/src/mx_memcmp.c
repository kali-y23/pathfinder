#include "libmx.h"

int mx_memcmp(const void *s1, const void *s2, size_t n) {
    int res = mx_strncmp((const char *) s1, (const char *) s2, n);
    return (res > 0) ? res : res * -1;
}
