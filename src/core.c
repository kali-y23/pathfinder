#include "pathfinder.h"

static t_vertex *create_unvisited_list(int root, int n) {
    char *root_str = mx_itoa(root);
    t_vertex *list = mx_create_vertex(root, 0, root_str);
    int i = 0;

    while (i < n) {
        if (i == root) {
            i += 1;
            continue;
        }
        mx_push_back_vertex(&list, i, -2, root_str);
        i++;
    }

    free(root_str);
    return list;
}


static int calc_index(t_vertex *unvisited) {
    t_vertex *node = unvisited;
    int min_distance = 2147483647;
    int index = -1;

    while (node) {
        if (node->distance > 0 && min_distance > node->distance) {
            min_distance = node->distance;
            index = node->index;
        }
        node = node->next;        
    }

    return index;
}


static void update_data(t_vertex *vertex, t_vertex *adj_vertex, int edge) {
    if (adj_vertex->distance == -2 
        || vertex->distance + edge < adj_vertex->distance) {

        adj_vertex->distance = vertex->distance + edge;
        mx_update_path(vertex, adj_vertex);
    }
    else if (vertex->distance + edge == adj_vertex->distance) {
        mx_append_new_min_path(vertex, adj_vertex);
    }
}


static void analyse_adjacent(int **matrix, t_vertex *unvisited, t_vertex *current_vertex, int n) {
    int index = current_vertex->index;
    int i = 0;

    while (i < n) {
        if (matrix[index][i] > 0) {
            t_vertex *vertex = mx_get_byindex(unvisited, i);
            if (vertex) {
                update_data(current_vertex, vertex, matrix[index][i]);
            }
        }
        i++;
    }
}


t_vertex *mx_dijkstra(int **matrix, int root, int n) {
    t_vertex *unvisited = create_unvisited_list(root, n);
    t_vertex *visited = NULL;

    while (unvisited && root != -1) {
        t_vertex *vertex = mx_get_byindex(unvisited, root);
        analyse_adjacent(matrix, unvisited, vertex, n);
        mx_push_back_vertex(&visited, vertex->index, vertex->distance, vertex->path);
        mx_pop_byindex(&unvisited, root);
        root = calc_index(unvisited);
    }

    if (unvisited) {
        mx_clear_vertex_list(&unvisited);
    }

    return visited;
}
