#include "pathfinder.h"


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
