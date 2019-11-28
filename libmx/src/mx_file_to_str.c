#include "libmx.h"

char *mx_file_to_str(const char *file) {
    int fd = open(file, O_RDONLY);
    int chars_read;
    char buf[64];
    char *result = malloc(1);
    char *temp = malloc(1);

    if (fd == -1) {
        return "-1";
    }

    while ((chars_read = read(fd, buf, sizeof(buf))) != 0) {
        if (chars_read < 0) {
            return NULL;
        }
        buf[chars_read] = '\0';
        temp = mx_strjoin(result, buf);
        mx_strdel(&result);
        result = mx_strdup(temp);
        mx_strdel(&temp);
    }

    if (close(fd) < 0) {
        return NULL;
    }

    return result;
}
