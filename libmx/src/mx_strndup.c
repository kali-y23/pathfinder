#include "libmx.h"

char *mx_strndup(const char *s1, size_t n) {
    char *str = mx_strnew(n + 1);
    size_t i = 0;

    while (str != NULL && i < n) {
        str[i] = s1[i];
        i++;
    }

    return str;
}
