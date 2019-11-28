#include "libmx.h"

char *mx_strncpy(char *dst, const char *src, int len) {
    int i = -1;
    while (i < len && src[++i]) {
        dst[i] = src[i];
    }
    while (i < len) {
        dst[i] = '\0';
        i++;
    }

    return dst;
}
