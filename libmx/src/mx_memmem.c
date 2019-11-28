#include "libmx.h"

void *mx_memmem(const void *big, size_t big_len, const void *little, size_t little_len) {
    if (big_len < little_len || little_len == 0 || big_len == 0) {
        return NULL;
    }

    size_t i = 0;
    char *b = (char *) big;
    char *l = (char *) little;
    
    while (i < big_len - little_len + 1) {
        if (b[i] == l[0] && mx_strncmp(&b[i], l, little_len) == 0) {
            char *res = &b[i];
            return (void *) res;
        }
        i++;
    }

    return NULL;
}
