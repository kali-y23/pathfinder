#include "pathfinder.h"

void mx_error_hub(char **file) {

}

void mx_check_arguments(int argc) {
    if (argc != 2) {
        mx_print_error("usage: ./pathfinder [filename]\n");
        exit(-1);
    }
}
