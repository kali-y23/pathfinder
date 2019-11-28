#include "libmx.h"

int mx_random_int(int min, int max) {
    srand(time(0));
    return min + (rand() % max - min + 1);
}
