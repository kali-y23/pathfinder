#include "libmx.h"

int mx_count_substr(const char *str, const char *sub) {
    if (str == NULL || sub == NULL) {
        return -1;
    }

    int len = mx_strlen(sub);
    int i = -1;
    int counter = 0;
    
    while (str[++i]) {
        if (str[i] == sub[0] && mx_strncmp(&str[i], sub, len) == 0) {
            counter++;
        }
    }

    return counter;
}
