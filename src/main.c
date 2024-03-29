#include "pathfinder.h"


int main(int argc, char **argv) {
    mx_check_arguments(argc);
    t_data *data = mx_parsing(argv[1]);

    int i = 0;
    while (i < data->n - 1) {
        t_vertex *output = mx_dijkstra(data->matrix, i, data->n);
        mx_process_output(data->matrix, data->set, &output);
        mx_clear_vertex_list(&output);
        i++;
    }
    mx_release_memory(data);
}
