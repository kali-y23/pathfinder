#include "libmx.h"

void mx_clear_list(t_list **list) {
	while (*list) {
		mx_pop_front(list);
	}

	list = NULL;
}
