#include "pathfinder.h"
#include <stdio.h>

void print_list(t_vertex *list) {
    t_vertex *vertex = list;
    if (!vertex) {
        printf("(null)\n");
        return;
    }
    while (vertex) {
        printf("index: %d, distance: %d, path: %s\n", vertex->index, vertex->distance, vertex->path);
        vertex = vertex->next;
    }
    printf("\n");
}

int main(int argc, char **argv) {
    // int n = 7;
    // // int matrix_stack[4][4] = {
    // //     {0, 8, 10, -1},
    // //     {8, 0, 3, -1},
    // //     {10, 3, 0, 5},
    // //     {-1, -1, 5, 0}
    // // };

    // // int matrix_stack[5][5] = {
    // //     {0, 3, 1, -1, -1},
    // //     {3, 0, 7, 5, 1},
    // //     {1, 7, 0, 2, -1},
    // //     {-1, 5, 2, 0, 7},
    // //     {-1, 1, -1, 7, 0}
    // // };


    // char **set = malloc(sizeof(char *) * n);
    // // char *stack_set[] = {"Greenland", "Bananal", "Fraser", "Java"};
    // // char *stack_set[] = {"A", "B", "C", "D", "E"};
    // char *stack_set[] = {"Home", "BusStop", "Work", "Taxi", "Metro", "Gym", "Park"};
    // int k = 0;
    // while (k < n) {
    //     *(set + k) = mx_strdup(stack_set[k]);
    //     k++;
    // }

    // mx_release_memory(matrix, set, n);
    // // system("leaks pathfinder");

    t_data *data = mx_parsing(argv[1]);
    argc = 0;

    //int n = data->n;
    // int matrix_stack[7][7] = {
    //     {0, 4, -1, 1, 6, -1, -1},
    //     {4, 0, 7, -1, -1, -1, 18},
    //     {-1, 7, 0, 10, 8, 2, -1},
    //     {1, -1, 10, 0, -1, 12, -1},
    //     {6, -1, 8, -1, 0, -1, 16},
    //     {-1, -1, 2, 12, -1, 0, -1},
    //     {-1, 18, -1, -1, 16, -1, 0}
    // };

    // int **matrix = malloc(sizeof(int *) * n);
    // int i = 0;
    // int j = 0;

    // while (i < n) {
    //     matrix[i] = malloc(sizeof(int) * n);
    //     j = 0;

    //     while (j < n) {
    //         matrix[i][j] = matrix_stack[i][j];
    //         j++;
    //     }
    //     i++;
    // }

    // for (int i = 0; i < data->n; i++) {
    //     for (int j = 0; j < data->n; j++) {
    //         mx_printint(data->matrix[i][j]);
    //         mx_printchar(' ');
    //     }
    //     mx_printchar('\n');
    // }

    int i = 0;
    while (i < data->n - 1) {
        t_vertex *output = mx_dijkstra(data->matrix, i, data->n);
        mx_process_output(data->matrix, data->set, &output);
        // print_list(output); - memory leak hint here
        mx_clear_vertex_list(&output);
        i++;
    }
}
