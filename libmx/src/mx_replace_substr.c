#include "libmx.h"

char *mx_replace_substr(const char *str, const char *sub, const char *replace) {
    if (!str || !sub || !replace) {
        return NULL;
    }

    int count = mx_count_substr(str, sub);
    int sub_len = mx_strlen(sub) * count;
    int rep_len = mx_strlen(replace) * count;
    int str_len = mx_strlen(str);
    int index;

    char *result = mx_strnew(str_len - sub_len + rep_len);

    while ((index = mx_get_substr_index(str, sub)) != -1) {
        char *temp = mx_strndup(str, index);
        mx_strcat(result, temp);
        mx_strcat(result, replace);
        str += index + (sub_len / count);
        mx_strdel(&temp);
    }
    
    mx_strcat(result, str);
    return result;
}
