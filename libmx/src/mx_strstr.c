#include "libmx.h"

char *mx_strstr(const char *haystack, const char *needle) {
    if (needle == NULL || needle[0] == '\0') {
        return (char *) haystack;
    }

    int len = mx_strlen(needle);
    int i = -1;
    
    while (haystack[++i]) {
        if (haystack[i] == needle[0] && mx_strncmp(&haystack[i], needle, len) == 0) {
            return (char *) &haystack[i];
        }
    }

    return NULL;
}
