#include "pathfinder.h"
#include <stdio.h>

static void write_set(char **set, char **names_strarr, int n, int *index) {
    for (int i = 0; names_strarr[i]; i++) {
        int duplicate = 0;

        for (int j = 0; set[j]; j++) {
            if (mx_strcmp(set[j], names_strarr[i]) == 0) {
                duplicate = 1;
                break;
            }
        }

        if (duplicate) {
            continue;
        }

        set[*index] = mx_strdup(names_strarr[i]);
        *index += 1;

        if (*index >= n) {
            mx_invalid_number_of_isles(n, *index);
        }
    }
}


static char **parse_set(char **strarr, int n) {
    char **set = mx_create_set(n);
    int index = 0;

    // i starts with 1 beacause 1st line is number of isles
    for (int i = 1; strarr[i]; i++) {
        int distance = 0;
        char **names_strarr = mx_get_names_strarr(strarr[i], &distance);
        write_set(set, names_strarr, n, &index);
        mx_del_strarr(names_strarr);
    }

    mx_invalid_number_of_isles(index, n);

    return set;
}


static int **parse_matrix(char **strarr, char **set, int n) {
    int **matrix = mx_create_matrix(n);

    for (int i = 1; strarr[i]; i++) {
        int distance = -2;
        char **names_strarr = mx_get_names_strarr(strarr[i], &distance);
        int index1 = mx_get_str_index(set, names_strarr[0]);
        int index2 = mx_get_str_index(set, names_strarr[1]);

        matrix[index1][index2] = distance;
        matrix[index2][index1] = distance;
        mx_del_strarr(names_strarr);
    }

    return matrix;
}


t_data *mx_parsing(char *filename) {
    t_data *data = malloc(sizeof(t_data));

    if (!data) {
        return NULL;
    }

    char *file = mx_file_to_str(filename);
    char **strarr = mx_strsplit(file, '\n');

    mx_error_hub(strarr, filename);

    data->n = mx_atoi(strarr[0]);
    data->set = parse_set(strarr, data->n);
    data->matrix = parse_matrix(strarr, data->set, data->n);

    mx_del_strarr(strarr);
    free(file);

    return data;
}

