#include "libmx.h"

void mx_print_strarr(char **arr, const char *delim) {
    if (!arr || !delim) {
        return;
    }

    int i = -1;
    while (arr[++i]) {
        mx_printstr(arr[i]);
        mx_printstr(delim);
    }

    mx_printchar('\n');
}
