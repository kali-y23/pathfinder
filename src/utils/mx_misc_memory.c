#include "pathfinder.h"

void mx_clear_vertex_list(t_vertex **list) {
	while (*list) {
		mx_pop_front_vertex(list);
	}

	list = NULL;
}

void mx_release_memory(int **matrix, char **set, int n) {
    for (int i = 0; i < n; i++) {
        free(set[i]);
        free(matrix[i]);
    }

    free(matrix);
    free(set);
}
