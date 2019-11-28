#include "libmx.h"

void mx_push_index(t_list **list, void *data, int index) {
	if (index <= 0 || *list == NULL) {
		mx_push_front(list, data);
	}
	else if (index >= mx_list_size(*list)) {
		mx_push_front(list, data);
	}
	else {
		t_list *node = *list;
		int counter = 0;

		while (counter < index - 1) {
			node = node->next;
			counter++;
		}

		t_list *new_node = mx_create_node(data);
		new_node->next = node->next;
		node->next = new_node;
	}
}
