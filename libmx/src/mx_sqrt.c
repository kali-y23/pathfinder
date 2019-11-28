#include "libmx.h"

int mx_sqrt(int x) {
	if (x <= 0) {
		return 0;
	}
	else if (x == 1) {
		return 1;
	}

	int min = 1;
	int max = x / 2;

	if (x / 2 > 46340) {
		max = 46340;
	} 

	while (min <= max) {
		int mid = (min + max) / 2;

		if (mid * mid == x) {
			return mid;
		}
		else if (mid * mid > x) {
			max = mid - 1;
		}
		else {
			min = mid + 1;
		}
	}

	return 0;
}
