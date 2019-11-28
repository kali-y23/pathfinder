#include "libmx.h"

static int count_hex_chars(int num) {
    int len = 0;
    while (num) {
        num = num / 16;
        len++;
    }
    return len;
}

char *mx_nbr_to_hex(unsigned long nbr) {
    if (nbr == 0) {
    	return "0";
    }

    int i = 0;
    int temp = 0;
    int len = count_hex_chars(nbr);
    char *reverse = mx_strnew(len);

    while (nbr) {
        temp = nbr % 16;
        reverse[i] = (temp < 10) ? temp + 48 : temp + 87;
        nbr = nbr / 16;
        i++;
    }

    mx_str_reverse(reverse);
    return reverse;
}
