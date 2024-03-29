#include "libmx.h"

static int partition(char **arr, int left, int right, int *count) {
   int l = left;
   int r = right;
   char *pivot = arr[left + (right - left) / 2];
   while (l <= r) {
       while (mx_strlen(arr[l]) < mx_strlen(pivot)) {
           l++;
       }
       while (mx_strlen(arr[r]) > mx_strlen(pivot)) {
           r--;
       }
       if (l <= r) {
           if (l != r && mx_strlen(arr[r]) != mx_strlen(arr[l])) {
               mx_swap_strings(&arr[l], &arr[r]);
               (*count)++;
           }
           l++;
           r--;
       }
   }
   return l;
}

int mx_quicksort(char **arr, int left, int right) {
   if (!arr) {
       return -1;
   }
   int count = 0;
   int pi = partition(arr, left, right, &count);
   if (left < pi - 1) {
       count += mx_quicksort(arr, left, pi - 1);
   }
   if (pi < right) {
       count += mx_quicksort(arr, pi, right);
   }
   return count;
}
