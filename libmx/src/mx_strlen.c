#include "libmx.h"

int mx_strlen(const char *s) {
    int i = 0;

    while(s[i]) {
        i++;
    }
    return i;
}

int mx_strarr_len(char **strarr) {
    int len = 0;

    for (; strarr[len]; len++);
    return len;
}
