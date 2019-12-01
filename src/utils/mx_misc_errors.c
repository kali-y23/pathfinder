#include "pathfinder.h"

void mx_empty_line(char **strarr, char *file) {
    int lines = mx_count_substr(file, "\n") + 1;
    if (lines != mx_strarr_len(strarr)) {
        int counter = 0;
        for (int i = 1; file[i]; i++) {
            if (file[i] == '\n') {
                counter++;
            }
            if (file[i - 1] == '\n' && file[i] == '\n') {
                mx_print_line_error(counter - 1);
            }
        }
    }
}

void mx_print_line_error(int i) {
    char *line = mx_itoa(i + 1);
    mx_print_error("error: line ");
    mx_print_error(line);
    mx_print_error(" isn't valid\n");
    exit(-1);
}

void mx_validate_names(char *names, int line) {
    char **names_strarr = mx_strsplit(names, '-');

    if (mx_strarr_len(names_strarr) != 2) {
        mx_del_strarr(names_strarr);
        mx_print_line_error(line);
    }
    else if (mx_strcmp(names_strarr[0], names_strarr[1]) == 0) {
        mx_del_strarr(names_strarr);
        mx_print_line_error(line);
    }

    for (int i = 0; names[i]; i++) {
        if (names[i] == '-' && names[i + 1] == '-') {
            mx_del_strarr(names_strarr);
            mx_print_line_error(line);
        }
        else if (!mx_isalpha(names[i]) && names[i] != '-') {
            mx_del_strarr(names_strarr);
            mx_print_line_error(line);
        }
    }

    mx_del_strarr(names_strarr);
}

void mx_validate_distance(char *distance_str, int line) {
    for (int i = 0; distance_str[i]; i++) {
        if (!mx_isdigit(distance_str[i])) {
            mx_print_line_error(line);
        }
    }
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
