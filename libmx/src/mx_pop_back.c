#include "libmx.h"

void mx_pop_back(t_list **list) {
	if (*list) {
		t_list *node = *list;
		t_list *last_node = NULL;

		while (node->next->next) {
			node = node->next;
		}

		last_node = node->next;
		node->next = NULL;

		last_node->data = NULL;
		last_node->next = NULL;
		free(last_node);
	}
}
