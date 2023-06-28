#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of ints in ascending
 * @list: list to sort
 * Return: void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *head, *next, *prev, *tmp;
	int swap;

	if (!list || !(*list) || !((*list)->next))
		return;

	head = *list;
	while (head && head->next)
	{
		swap = 0;
		tmp = head;
		next = head->next;
		while (tmp && tmp->n > next->n)
		{
			prev = tmp->prev;
			if (next && tmp->n > next->n)
			{
				tmp ->prev = next;
				tmp->next = next->next;
				if (tmp->next)
					tmp->next->prev = tmp;
				next->next = tmp;
				next->prev = prev;
				if (prev)
					prev->next = next;
				else
					*list = next;
				print_list(*list);
			}
			tmp = prev;
			swap = 1;
		}
		if (!swap)
			head = head->next;
	}
}
