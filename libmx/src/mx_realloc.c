#include "libmx.h"

void *mx_realloc(void *ptr, size_t size) {
    if (!ptr) {
        return malloc(size);
    }

    void *new_ptr = malloc(size);
    if (new_ptr) {
        mx_memcpy(new_ptr, ptr, size);
        free(ptr);
    }

    return new_ptr;
}
