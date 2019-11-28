#include "libmx.h"

void *mx_memrchr(const void *s, int c, size_t n) {
    char *str = (char *) s;
    while (--n) {
        if (str[n] == c) {
            return (void *) &str[n];
        } 
        n--;
    }
    return NULL;
}
