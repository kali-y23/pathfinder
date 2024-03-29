#include "pathfinder.h"
static void loop_iteration(t_vertex **visited, t_vertex *vertex);


static char **split_path(t_vertex *vertex, int *len) {
    char **strarr = mx_strsplit(vertex->path, '|');

    if (mx_strarr_len(strarr) != 1) {
        free(vertex->path);
        vertex->path = mx_strdup(strarr[0]);
        *len = mx_strarr_len(strarr) - 1;
        return strarr;
    }
    mx_del_strarr(strarr);
    return NULL;
}


static int *analyse_path(char **strarr, int len) {
    int *paths = malloc(sizeof(int) * len);

    for (int i = 0; i < len; i++) {
        paths[i] = mx_atoi(strarr[i + 1]);
    }
    return paths;
}


static void create_nodes(t_vertex **visited, t_vertex *vertex, int *paths, int len) {
    for (int i = 0; i < len; i++) {
        t_vertex *source = mx_get_byindex(*visited, paths[i]);
        t_vertex *new = NULL;

        loop_iteration(visited, source);
        int sub_paths = mx_count_nodes(visited, paths[i]);
        for (int j = 0; j < sub_paths; j++) {
            if (mx_strncmp(vertex->path, source->path, mx_strlen(source->path)) != 0) {
                new = mx_push_next(vertex, vertex->index, vertex->distance, "");
                mx_update_path(source, new);
            }
            source = source->next;
        }
    }
}


static void loop_iteration(t_vertex **visited, t_vertex *vertex) {
    int len = 0;
    char **strarr = split_path(vertex, &len);

    if (strarr) {
        int *paths = analyse_path(strarr, len);
        create_nodes(visited, vertex, paths, len);
        free(paths);
        mx_del_strarr(strarr);
    }
}


void mx_unpack_multiples(t_vertex **visited, t_vertex *vertex) {
    while (vertex) {
        loop_iteration(visited, vertex);
        vertex = vertex->next;
    }
}
