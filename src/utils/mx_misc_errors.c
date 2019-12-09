#include "pathfinder.h"


void mx_empty_line(char **strarr, char *file) {
    int lines = mx_count_substr(file, "\n") + 1;
    int counter = 0;

    if (lines != mx_strarr_len(strarr)) {
        counter = 0;
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


static void check_char_by_char(char *names, char **names_strarr, int line) {
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
    check_char_by_char(names, names_strarr, line);
    mx_del_strarr(names_strarr);
}
