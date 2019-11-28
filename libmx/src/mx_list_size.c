#include "libmx.h"

int mx_list_size(t_list *list) {
	t_list *node = list;
	int counter = 0;

	while (node) {
		node = node->next;
		counter++;
	}

	return counter;
}
