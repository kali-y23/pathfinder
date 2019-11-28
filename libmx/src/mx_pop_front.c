#include "libmx.h"

void mx_pop_front(t_list **list) {
	if (*list) {
		t_list *node = *list;
		*list = node->next;

		node->data = NULL;
		node->next = NULL;
		free(node);
	}
}
