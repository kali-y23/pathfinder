#include "pathfinder.h"

t_vertex *mx_get_byindex(t_vertex *list, int index) {
	t_vertex *node = list;

	while (node) {
		if (node->index == index) {
			return node;
		}
		node = node->next;
	}
	return NULL;
}


static void pop_vertex(t_vertex *node) {
	t_vertex *tmp = node->next;

	node->next = node->next->next;		
	tmp->next = NULL;
	free(tmp->path);
	free(tmp);
}


t_vertex *mx_pop_byindex(t_vertex **list, int index) {
	if (!list || *list == NULL) {
		return NULL;
	}
	t_vertex *node = *list;

	if (node->index == index) {
		mx_pop_front_vertex(list);
		return NULL;
	}
	while (node->next) {
		if (node->next->index == index) {
			pop_vertex(node);
			break;
		}
		node = node->next;
	}
	return node->next;
}
