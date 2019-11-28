#include "libmx.h"


int mx_float_compare(void *vn1, void *vn2) {
	float *n1 = (float *) vn1;
	float *n2 = (float *) vn2; 
	float dif = *n1 - *n2;

	return (int) dif;
}

int mx_int_compare(void *vn1, void *vn2) {
	int *n1 = (int *) vn1;
	int *n2 = (int *) vn2;
	return *n1 - *n2;
}

