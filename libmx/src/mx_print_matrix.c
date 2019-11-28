#include "libmx.h"

void mx_print_matrix(int **matrix, int n) {
    if (!matrix) {
        return;
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            mx_printint(matrix[i][j]);
            mx_printchar(' ');
        }
        mx_printchar('\n');
    }
}
