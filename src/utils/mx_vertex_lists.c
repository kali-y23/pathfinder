#include "pathfinder.h"


t_vertex *mx_create_vertex(int index, int distance, char *path) {
	t_vertex *node = malloc(sizeof(t_vertex));

	if (!node)
		return NULL;
	node->index = index;
	node->distance = distance;
	node->path = mx_strdup(path);
	node->next = NULL;
	return node;
}


void mx_pop_back_vertex(t_vertex **list) {
	if (*list) {
		t_vertex *node = *list;
		t_vertex *last_node = NULL;

		while (node->next->next) {
			node = node->next;
		}
		last_node = node->next;
		if (last_node == NULL) {
			mx_pop_front_vertex(list);
			return;
		}
		node->next = NULL;
		last_node->next = NULL;
		free(last_node->path);
		free(last_node);
	}
}


void mx_pop_front_vertex(t_vertex **list) {
	if (list && *list) {
		t_vertex *node = *list;

		*list = node->next;
		node->next = NULL;
		free(node->path);
		free(node);
	}
}


t_vertex *mx_push_back_vertex(t_vertex **list, int index, int distance, char *path) {
	t_vertex *new_node = mx_create_vertex(index, distance, path);
	t_vertex *node = NULL;

	if (list && *list) {
		node = *list;
		while (node->next)
			node = node->next;
		node->next = new_node;
	}
	else
		*list = new_node;
	return new_node;
}

