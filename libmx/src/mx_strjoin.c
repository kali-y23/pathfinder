#include "libmx.h"

char *mx_strjoin(const char *s1, const char *s2) {
    if (!s1 && !s2) {
        return NULL;
    }
    else if (!s1) {
        return mx_strdup(s2);
    }
    else if (!s2) {
        return mx_strdup(s1);
    }

    char *newstr = mx_strnew(mx_strlen(s1) + mx_strlen(s2));
    if (!newstr) {
        return NULL;
    }

    int i = 0;
    int si = -1;

    while(s1[++si]) {
        newstr[i] = s1[si];
        i++;
    }
    si = -1;
    while(s2[++si]) {
        newstr[i] = s2[si];
        i++;
    }

    return newstr;
}
