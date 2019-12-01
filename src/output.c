#include "pathfinder.h"

static void print_path(char **set, t_vertex *vertex, int source) {
    mx_printstr("Path: ");
    mx_printstr(set[source]);
    mx_printstr(" -> ");
    mx_printstr(set[vertex->index]);
    mx_printchar('\n');
}


static int *print_route(char **set, t_vertex *vertex) {
    int *indices = mx_parse_path(vertex->path);
    
    mx_printstr("Route: ");
    mx_printstr(set[indices[1]]);

    for (int i = 2; i < indices[0]; i++) {
        mx_printstr(" -> ");
        mx_printstr(set[indices[i]]);
    }

    mx_printchar('\n');
    return indices;
}


static void print_distance(int **matrix, int *route, int distance) {
    mx_printstr("Distance: ");
    mx_printint(matrix[route[1]][route[2]]);
    int i = 2;

    if (i < route[0] - 1) {
        for (; i < route[0] - 1; i++) {
            mx_printstr(" + ");
            mx_printint(matrix[route[i]][route[i + 1]]);
        }
        
        mx_printstr(" = ");
        mx_printint(distance);
        mx_printchar('\n');
    }
    else {
        mx_printchar('\n');
    }
}


static void print_output(int **matrix, char **set, t_vertex *vertex, int source) {
    mx_print_line();
    print_path(set, vertex, source);
    int *route = print_route(set, vertex);
    print_distance(matrix, route, vertex->distance);
    mx_print_line();
    free(route);
}


void mx_process_output(int **matrix, char **set, t_vertex **head) {
    t_vertex *vertex = *head;
    if (!vertex) {
        return;
    }
    
    int source = vertex->index;
    mx_sort_byindex(head);

    mx_unpack_multiples(head, vertex);
    vertex = vertex->next;
    

    while (vertex) {
        if (vertex->index > source) {
            print_output(matrix, set, vertex, source);
        }
        vertex = vertex->next;
    }
}
