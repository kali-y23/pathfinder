#include "libmx.h"

unsigned long mx_hex_to_nbr(const char *hex) {
    int len = 0;
    unsigned long dec = 0;
    unsigned long base = 1;

    while (hex[len]) {
		len++;
    }

    for (; len >= 0; len--) {
		if (hex[len] > 47 && hex[len] < 58) {
			dec += (hex[len] - 48) * base;
			base *= 16;
		}
		else if (hex[len] >= 'A' && hex[len] <= 'F') {
			dec += (hex[len] - 55) * base;
			base *= 16;
		}
		else if (hex[len] >= 'a' && hex[len] <= 'f') {
			dec += (hex[len] - 87) * base;
			base *= 16;
		}
    }

    return dec;
}


