#include "libmx.h"

int mx_get_char_index(const char *str, char c) {
    if (!str) {
        return -2;
    }

    int i = -1;
    while (str[++i]) {
        if (str[i] == c) {
            return i;
        }
    }

    return -1;
}

int mx_get_charn_index(const char *str, char c, int n) {
    if (!str) {
        return -2;
    }

    int i = 0;
    while (i < n) {
        if (str[i] == c) {
            return i;
        }
        i++;
    }

    return -1;
}
