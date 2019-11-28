#include "libmx.h"

void *mx_memmove(void *dst, const void *src, size_t len) {
   char *d = (char *) dst;
   char buf[len + 1];
   mx_strncpy(buf, (char *) src, len);
   size_t i = -1;

   while (++i < len) {
       d[i] = buf[i];
   }

   return (void *) dst;
}
