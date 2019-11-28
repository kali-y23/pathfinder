#include "libmx.h"

void mx_print_arr(int *arr, int n, char *delim) {
    if (!arr) {
        return;
    }

    for (int i = 0; i < n; i++) {
        mx_printint(arr[i]);
        mx_printstr(delim);
    }
    mx_printchar('\n');
}
