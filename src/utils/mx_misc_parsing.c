#include "pathfinder.h"

int **mx_create_matrix(int n) {
    int **matrix = malloc(sizeof(int *) * n);

    if (!matrix)
        return NULL;

    for (int i = 0; i < n; i++) {
        matrix[i] = malloc(sizeof(int) * n);
        
        if (!matrix[i])
            return NULL;
     
        for (int j = 0; j < n; j++) {
            if (i == j) {
                matrix[i][j] = 0;
            }
            else {
                matrix[i][j] = -1;
            }
        }
    }
    return matrix;
}


char **mx_create_set(int n) {
    char **set = malloc(sizeof(char *) * (n + 1));

    for (int i = 0; i < n; i++) {
        set[i] = NULL;
    }

    return set;
}


int mx_get_str_index(char **strarr, char *str) {
    for (int i = 0; strarr[i]; i++) {
        if (mx_strcmp(strarr[i], str) == 0) {
            return i;
        }
    }
    return -1;
}


char **mx_get_names_strarr(char *str, int *distance) {
    char **isles = mx_strsplit(str, ',');
    char *names = isles[0];
    *distance = mx_atoi(isles[1]);

    char **names_strarr = mx_strsplit(names, '-');
    mx_del_strarr(isles);

    return names_strarr;
}
