#include "libmx.h"

static int count_integers(int number) {
    int i = 0;

    while (number) {
        number /= 10;
        i++;
    }
    return i;
}

char *mx_itoa(int number) {
    int len = 0;

    if (number == 0) {
        return mx_strdup("0");
    }
    else if (number == -2147483648) {
        return mx_strdup("−2147483648");
    }
    else if (number < 0) {
        number *= -1;
        len += 1;
    }
    
    len += count_integers(number);
    char *str = mx_strnew(len);

    while (len) {
        str[len - 1] = number % 10 + '0';
        if (number == 0) {
            str[len - 1] = '-';
        }
        number /= 10;
        len--;
    }

    return str;
}
