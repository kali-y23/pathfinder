#include "libmx.h"

int mx_get_substr_index(const char *str, const char *sub) {
    if (str == NULL || sub == NULL) {
        return -2;
    }

    int len = mx_strlen(sub);
    int i = -1;
    
    while (str[++i]) {
        if (str[i] == sub[0] && mx_strncmp(&str[i], sub, len) == 0) {
            return i;
        }
    }

    return -1;
}
