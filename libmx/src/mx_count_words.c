#include "libmx.h"

int mx_count_words(const char *str, char c) {
    if (str == NULL) {
        return -1;
    }

    int bunny = 1;
    int i = -1;
    int counter = 0;

    while (str[++i]) {
        if (str[i] == c && bunny == 0) {
            bunny = 1;
        }
        else if (str[i] != c && bunny == 1) {
            counter++;
            bunny = 0;
        }
    }

    return counter;
}
