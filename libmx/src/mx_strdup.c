#include "libmx.h"

char *mx_strdup(const char *str) {
	char *dup = mx_strnew(mx_strlen(str) + 1);
	if (dup == NULL) {
		return NULL;
	}

	return mx_strcpy(dup, str);	
}
