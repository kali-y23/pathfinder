#include "libmx.h"

t_list *mx_sort_list(t_list *list, bool (*cmp)(void *a, void *b)) {
  t_list *temp = NULL;
  t_list *store = list;
  t_list *curr = list;
  void *swap_data;
    
  while (list) {
    temp = store;
    while (temp) {
      if (temp->next && cmp(temp->data, temp->next->data)) {
        swap_data = temp->data;
        temp->data = temp->next->data;
        temp->next->data = swap_data;
      }
      temp = temp->next;
    }
    list = list->next;
  }
  return curr;
}
