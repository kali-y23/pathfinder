#include "libmx.h"

void mx_foreach_list(t_list *list, void (*f)(t_list *node)) {
	t_list *node = list;

	while (node) {
		(*f)(node);
		node = node->next;
	}
}
