#include "pathfinder.h"
static t_vertex *merge(t_vertex *left, t_vertex *right);


static int cmp_path(char *left, char *right) {
	int *left_path = mx_parse_path(left);
	int *right_path = mx_parse_path(right);

	for (int i = 1; (i < left_path[0] && i < right_path[0]); i++) {
		if (left_path[i] > right_path[i]) {
			return 1;
		}
		else if (left_path[i] > right_path[i]) {
			return 0;
		}
	}
	free(left_path);
	free(right_path);
	return 0;
}


static t_vertex *deep_compare(t_vertex *left, t_vertex *right) {
    t_vertex *result = NULL;

    if (cmp_path(left->path, right->path) == 1) {
        result = right;
        result->next = merge(left, right->next);
    } 
    else {
        result = left;
        result->next = merge(left->next, right);
    }
    return result;
}


static t_vertex *merge(t_vertex *left, t_vertex *right) {
	t_vertex *result = NULL;

	if (!left)
		return right;
	else if (!right)
		return left;
	if (right->index > left->index) { //CHANGE SIGN TO REVERSE SORTING ORDER
		result = left;
		result->next = merge(left->next, right);
	}
	else if (right->index < left->index) {
		result = right;
		result->next = merge(left, right->next);
	}
	else {
        result = deep_compare(left, right);
	}
	return result;
}


static void divide(t_vertex *head, t_vertex **a, t_vertex **b) {
	t_vertex *slow = head;
	t_vertex *fast = head->next;

	while (fast) {
		fast = fast->next;
		if (fast) {
			slow = slow->next;
			fast = fast->next;
		}
	}
	*a = head;
	*b = slow->next;
	slow->next = NULL;
}


void mx_sort_byindex(t_vertex **head_ptr) {
	t_vertex *head = *head_ptr;
	t_vertex *a = NULL;
	t_vertex *b = NULL;

	if (!head || !(head->next)) {
		return;
	}
	divide(head, &a, &b);
	mx_sort_byindex(&a);
	mx_sort_byindex(&b);
	*head_ptr = merge(a, b);
}
