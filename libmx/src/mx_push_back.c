#include "libmx.h"

void mx_push_back(t_list **list, void *data) {
	t_list *new_node = mx_create_node(data);
	if (*list) {
		t_list *node = *list;

		while (node->next) {
			node = node->next;
		}

		node->next = new_node;
	}
	else {
		*list = new_node;
	}
}
