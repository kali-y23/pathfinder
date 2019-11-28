#include "libmx.h"

char *mx_strcat(char *restrict s1, const char *restrict s2) {
    int s1_len = mx_strlen(s1);
    int i = -1;

    while (s2[++i]) {
        s1[s1_len] = s2[i];
        s1_len++;
    }

    s1[s1_len] = '\0';
    return s1;
}
