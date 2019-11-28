#include "libmx.h"

void mx_printstrn(char *str, int n) {
    int i = 0;

    while (i < n) {
        write(1, &str[i], 1);
    }
}
