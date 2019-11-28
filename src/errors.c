#include "pathfinder.h"

static void first_line_invalid(char *line) {
    for (int i = 0; line[i]; i++) {
        if (!mx_isdigit(line[i]) && line[i] != '\n') {
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
    // line_invlid(file);
}

void mx_invalid_number_of_isles(int given_n, int real_n) {
    if (given_n != real_n) {
        mx_print_error("error: invalid number of islands\n");
        exit(-1);
    }
}

void mx_check_arguments(int argc) {
    if (argc != 2) {
        mx_print_error("usage: ./pathfinder [filename]\n");
        exit(-1);
    }
}
