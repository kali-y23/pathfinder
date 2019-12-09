#include "pathfinder.h"


void mx_push_front_vertex(t_vertex **list, int index, int distance, char *path) {
	t_vertex *new_node = mx_create_vertex(index, distance, path);

	if (list && *list) {
		new_node->next = *list;
		*list = new_node;
	}
	else {
		*list = new_node;
	}
}


t_vertex *mx_push_next(t_vertex *vertex, int index, int distance, char *path) {
	t_vertex *new = mx_create_vertex(index, distance, path);
	
	new->next = vertex->next;
	vertex->next = new;
	return new;
}


int mx_count_nodes(t_vertex **head, int index) {
	t_vertex *vertex = *head;
	int count = 0;

	while (vertex) {
		if (vertex->index == index) {
			count++;
		}
		vertex = vertex->next;
	}
	return count;
}
