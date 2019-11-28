#include "libmx.h"

t_list *mx_get_byindex(t_list *list, int index) {
	t_list *node = list;
	int counter = 0;

	while (node && counter < index) {
		node = node->next;
		counter++;
	}

	return node;
}

t_list *mx_find_bydata(t_list *list, void *data) {
	t_list *node = list;

	while (node) {
		if (node->data == data) {
			return node;
		}
		node = node->next;
	}

	return NULL;
}

