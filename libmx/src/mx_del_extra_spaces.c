#include "libmx.h"

static int mx_count_extra_spaces(const char *str) {
    int i = 0;
    int counter = 0;
    
    while (str[i + 1]) {
        if (mx_isspace(str[i]) && mx_isspace(str[i + 1])) {
            counter++;
        }
        i++;
    }

    return counter;
}

static char *mx_fill_clean_string(char *str, char *new_str) {
    int i_str = -1;
    int i_newstr = 0;

    while (str[++i_str + 1]) {
        if (mx_isspace(str[i_str]) && mx_isspace(str[i_str + 1])) {
            continue;
        }
        else {
            new_str[i_newstr] = (mx_isspace(str[i_str])) ? ' ' : str[i_str];
            i_newstr++;
        }
    }
    
    new_str[i_newstr] = str[i_str];
    return new_str;
}

char *mx_del_extra_spaces(const char *str) {
    char *trim = mx_strtrim(str);
    int len = mx_strlen(trim);
    int spaces = mx_count_extra_spaces(trim);

    char *new_str = mx_strnew(len - spaces);
    new_str = mx_fill_clean_string(trim, new_str);
    free(trim);

    return new_str;
}
