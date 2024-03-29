#include "libmx.h"


static t_list *merge(t_list *left, t_list *right, bool (*cmp)(void *, void *)) {
	t_list *result = NULL;

	if (left == NULL) {
		return right;
	}
	else if (right == NULL) {
		return left;
	}


	if (!cmp(left->data, right->data)) { //CHANGE SIGN HERE TO REVERSE SORTING ORDER
		result = left;
		result->next = merge(left->next, right, cmp);
	}
	else {
		result = right;
		result->next = merge(left, right->next, cmp);
	}

	return result;
}


static void divide(t_list *head, t_list **a, t_list **b) {
	t_list *slow = head;
	t_list *fast = head->next;

	while (fast != NULL) {
		fast = fast->next;
		if (fast != NULL) {
			slow = slow->next;
			fast = fast->next;
		}
	}

	*a = head;
	*b = slow->next;
	slow->next = NULL;
}


void mx_merge_sort(t_list **head_ptr, bool (*cmp)(void *, void *)) {
	t_list *head = *head_ptr;
	t_list *a = NULL;
	t_list *b = NULL;

	if (head == NULL || head->next == NULL) {
		return;
	}

	divide(head, &a, &b);

	mx_merge_sort(&a, cmp);
	mx_merge_sort(&b, cmp);

	*head_ptr = merge(a, b, cmp);
}

