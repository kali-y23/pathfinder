#include "libmx.h"

int mx_strcmp(const char *s1, const char *s2) {
	int i = 0;
	int diff = 0;

	while (s1[i] || s2[i]) {
		if (s1[i] != s2[i]) {
			diff = s1[i] - s2[i];
			return diff;
		}
		i++;
	}

	return 0;
}

int mx_strncmp(const char *s1, const char *s2, int n) {
	int i = 0;
	int diff = 0;

	while (i < n && (s1[i] || s2[i])) {
		if (s1[i] != s2[i]) {
			diff = s1[i] - s2[i];
			return diff;
		}
		i++;
	}

	return 0;
}

bool mx_strcmp_bool(char *s1, char *s2) {
	int cmp = mx_strcmp(s1, s2);

	if (cmp > 0) {
		return true;
	}
	
	return false;
}
