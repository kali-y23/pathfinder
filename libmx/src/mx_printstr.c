#include "libmx.h"

void mx_printstr(const char *s) {
    write(1, s, mx_strlen(s));
}

void mx_print_error(const char *s) {
    write(2, s, mx_strlen(s));
}
