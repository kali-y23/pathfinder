#include "libmx.h"

int mx_strnlen(const char *str, char stop) {
    int i = 0;

    while (str[i] && str[i] != stop) {
        i++;
    }

    return i;
}
