#include "libmx.h"

void mx_print_unicode(wchar_t c)
{
    char *str = mx_strnew(4);
    
    if (c <= 0x7F) {
        str[0] = (char)c;
        str[1] = 0;
    }
    else if (c <= 0x07FF) {
        str[0] = (char)(((c >> 6) & 0x1F) | 0xC0);
        str[1] = (char)(((c >> 0) & 0x3F) | 0x80);
        str[2] = '\0';
    }
    else if (c <= 0xFFFF) {
        str[0] = (char)(((c >> 12) & 0x0F) | 0xE0);
        str[1] = (char)(((c >> 6) & 0x3F) | 0x80);
        str[2] = (char)(((c >> 0) & 0x3F) | 0x80);
        str[3] = '\0';
    }
    else if (c <= 0x10FFFF) {
        str[0] = (char)(((c >> 18) & 0x07) | 0xF0);
        str[1] = (char)(((c >> 12) & 0x3F) | 0x80);
        str[2] = (char)(((c >> 6) & 0x3F) | 0x80);
        str[3] = (char)(((c >> 0) & 0x3F) | 0x80);
        str[4] = '\0';
    }
    else {
        str[0] = (char)0xEF;
        str[1] = (char)0xBF;
        str[2] = (char)0xBD;
        str[3] = '\0';
    }
    write(1, str, mx_strlen(str));
    mx_strdel(&str);
}
