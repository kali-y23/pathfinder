#include "libmx.h"

void mx_pop_index(t_list **list, int index) {
	if (index <= 0 || *list == NULL) {
		mx_pop_front(list);
	}
	else if (*list == NULL) {
		return;
	}
	else if (index >= mx_list_size(*list)) {
		mx_pop_back(list);
	}
	else {
		t_list *node = *list;
		int counter = 0;

		while (counter < index - 1) {
			node = node->next;
			counter++;
		}

		t_list *delete = node->next;
		mx_pop_front(&delete);
		node->next = delete;
		
	}
}
