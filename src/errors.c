#include "pathfinder.h"


static void line_invalid(char **file) {
    char **strarr = NULL;

    for (int i = 1; file[i]; i++) {
        strarr = mx_strsplit(file[i], ',');
        if (mx_strarr_len(strarr) != 2) {
            mx_print_line_error(i);
        }
        mx_validate_names(strarr[0], i);
        mx_validate_distance(strarr[1], i);
        mx_del_strarr(strarr);
    }
}


static void first_line_invalid(char *line) {
    for (int i = 0; line[i]; i++) {
        if (!mx_isdigit(line[i]) && line[i]) {
            mx_print_error("error: line 1 is not valid\n");
            exit(-1);
        }
    }
}


static void file_is_empty(char **file, char *filename) {
    if (!file[0]) {
        mx_print_error("error: file ");
        mx_print_error(filename);
        mx_print_error(" is empty\n");
        exit(-1);
    }
}


static void file_does_not_exist(char **file, char *filename) {
    if (file[0][0] == '-' && file[0][1] == '1') {
        mx_print_error("error: file ");
        mx_print_error(filename);
        mx_print_error(" does not exist\n");
        exit(-1);
    }
}


void mx_error_hub(char **file, char *filename) {
    file_is_empty(file, filename);
    file_does_not_exist(file, filename);
    first_line_invalid(file[0]);
    line_invalid(file);
}
