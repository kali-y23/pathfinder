#include "pathfinder.h"
#include <stdio.h>

int *mx_parse_path(char *path) {
    char **strarr = mx_strsplit(path, '-');
    int len = mx_strarr_len(strarr) + 1;
    int *arr = malloc(sizeof(int) * len);
    int i = 1;
    arr[0] = len;

    while (i < len) {
        arr[i] = mx_atoi(strarr[i - 1]);
        i++;
    }

    mx_del_strarr(strarr);
    return arr;
}

void mx_print_line() {
    int i = 0;

    while (i < 40) {
        mx_printchar('=');
        i++;
    }

    mx_printchar('\n');
}

// ===================================================
// SUPPORT VERTICES WITH MULTIPLE SHORTEST PATHS BLOCK
// ===================================================
// static int *unpack_multiple(t_vertex **visited, t_vertex *vertex);


// static void create_nodes(t_vertex **visited, t_vertex *vertex, int *paths) {
//     int len = paths[0];
//     printf("createnodes %d\n", len);

//     for (int i = 1; i < len; i++) {
//         printf("loop started");
//         t_vertex *source_vertex = mx_get_byindex(*visited, paths[i]);
//         int *sub_paths;

//         if (!(sub_paths = unpack_multiple(visited, source_vertex))) {
//             *sub_paths = 1;
//         }

//         printf("nosegfault\n");
//         for (int j = 1; j < sub_paths[0]; j++) {
//             vertex = mx_push_back_vertex(&vertex, vertex->index, vertex->distance, mx_strdup(source_vertex->path));
//             mx_update_path(source_vertex, vertex);
//         }
//         printf("stillno\n");
//     }

//     printf("create nodes finished");
// }


// static int *unpack_multiple(t_vertex **visited, t_vertex *vertex) {
//     if (mx_get_char_index(vertex->path, '|') != -1) {

//         char **strarr = mx_strsplit(vertex->path, '|');
//         free(vertex->path);
//         vertex->path = mx_strdup(strarr[0]);
        
//         int len = mx_strarr_len(strarr);
//         int *paths = malloc(sizeof(int) * len);
//         paths[0] = len;

//         for (int i = 1; i < len; i++) {
//             paths[i] = mx_atoi(strarr[i]);

//         }

//         create_nodes(visited, vertex, paths);
//         mx_del_strarr(strarr);
//         free(paths);

//         return paths;
//     }
    
//     return NULL;
// }


// void mx_unpack_multiples(t_vertex **visited) {
//     t_vertex *vertex = *visited;

//     printf("start unpack\n");
//     while (vertex) {
//         printf("loop\n");
//         mx_printstr(vertex->path);
//         mx_printchar('\n');
//         unpack_multiple(visited, vertex);
//         //print_list(vertex);
//         vertex = vertex->next;
//     }

//     printf("end unpack\n");
// }

static void loop_iteration(t_vertex **visited, t_vertex *vertex);

static char **split_path(t_vertex *vertex, int *len) {
    if (mx_get_char_index(vertex->path, '|') != -1) {
        char **strarr = mx_strsplit(vertex->path, '|');
        
        free(vertex->path);
        vertex->path = mx_strdup(strarr[0]);

        *len = mx_strarr_len(strarr) - 1;
    
        return strarr;
    }

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
        loop_iteration(visited, source);
        int sub_paths = mx_count_nodes(visited, paths[i]);

        for (int j = 0; j < sub_paths; j++) {
            t_vertex *new = mx_push_next(vertex, vertex->index, vertex->distance, "");
            mx_update_path(source, new);

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

