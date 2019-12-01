#ifndef    PATHFINDER
#define    PATHFINDER

#include "libmx.h"


typedef struct s_data {
    int **matrix;
    char **set;
    int n;
} t_data;


typedef struct s_vertex {
    int index;
    int distance;
    char *path;
    struct s_vertex *next;
} t_vertex;


// DONT PUSH DELETE
void print_list(t_vertex *list);

void mx_error_hub(char **file, char *filename);
t_data *mx_parsing(char *filename);
t_vertex *mx_dijkstra(int **matrix, int root, int n);
void mx_process_output(int **matrix, char **set, t_vertex **head);


// Utils
    //Vertex lists
t_vertex *mx_create_vertex(int index, int distance, char *path);
void mx_pop_back_vertex(t_vertex **list);
void mx_pop_front_vertex(t_vertex **list);
t_vertex *mx_push_back_vertex(t_vertex **list, int index, int distance, char *path);
void mx_push_front_vertex(t_vertex **list, int index, int distance, char *path);
t_vertex *mx_push_next(t_vertex *vertex, int index, int distance, char *path);
int mx_count_nodes(t_vertex **head, int index);

    // Byindex
t_vertex *mx_get_byindex(t_vertex *list, int index);
t_vertex *mx_pop_byindex(t_vertex **list, int index);
void mx_sort_byindex(t_vertex **head_ptr);

    // Misc Parsing
int **mx_create_matrix(int n);
char **mx_create_set(int n);
int mx_get_str_index(char **strarr, char *str);
char **mx_get_names_strarr(char *str, int *distance);

    // Misc Core
void mx_update_path(t_vertex *vertex, t_vertex *adj_vertex);
void mx_append_new_min_path(t_vertex *vertex, t_vertex *adj_vertex);

    // Misc Memory
void mx_release_memory(t_data *data);
void mx_clear_vertex_list(t_vertex **list);

    // Misc Output
int *mx_parse_path(char *path);
void mx_print_line();
void mx_unpack_multiples(t_vertex **visited, t_vertex *vertex);

    // Misc Errors
void mx_validate_names(char *names, int line);
void mx_validate_distance(char *distance_str, int line);
void mx_check_arguments(int argc);
void mx_invalid_number_of_isles(int given_n, int real_n);
void mx_print_line_error(int i);
void mx_empty_line(char **strarr, char *file);

#endif
