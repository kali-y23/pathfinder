#include "pathfinder.h"
#include <stdio.h>

void mx_update_path(t_vertex *vertex, t_vertex *adj_vertex) {
    free(adj_vertex->path);
    char *s1 = mx_strjoin(vertex->path, "-");
    char *i_str = mx_itoa(adj_vertex->index);
    adj_vertex->path = mx_strjoin(s1, i_str);
    
    free(s1);
    free(i_str);
}


void mx_append_new_min_path(t_vertex *vertex, t_vertex *adj_vertex) {
    char *index_str = mx_itoa(vertex->index);
    char *str = mx_strjoin("|", index_str);
    char *path = mx_strdup(adj_vertex->path);
    adj_vertex->path = mx_strjoin(path, str);

    free(index_str);
    free(str);
    free(path);
}
