#include "libmx.h"

bool mx_isdigit(int c) {
    if (0x2f < c && c < 0x3a) {
        return 1;
    }
    else {
        return 0;
    }
}

bool mx_isspace(char c) {
    if (c == 32 || c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r') {
        return true;
    }
    else {
        return false;
    }
}

int mx_atoi(const char *str) {
    int i = -1;
    int sum = 0;
    int sign = 1;
    while (str[++i]) {
        if (!mx_isspace(str[i])) {
            if (str[i] == '-' && sign == 1) {
                sign = -1;
                i++;
            }
            if (!mx_isdigit(str[i])) {
                return -1;
            }
            else {
                sum = sum * 10 + str[i] - '0';
            }
        }
    }
    return sum * sign;
}
