#include "pathfinder.h"

void mx_clear_vertex_list(t_vertex **list) {
	while (*list) {
		mx_pop_front_vertex(list);
	}

	list = NULL;
}

void mx_release_memory(t_data *data) {
    for (int i = 0; i < data->n; i++) {
        free(data->set[i]);
        free(data->matrix[i]);
    }

    free(data->matrix);
    free(data->set);
    free(data);
}
