#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers using insertion
 * sort algorithm.
 *
 * @list: Given doubly linked list to be sorted
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *ptr;

	if (list == NULL || *list == NULL)
		return;

	for (ptr = (*list)->next; ptr != NULL; ptr = ptr->next)
	{
		while (ptr->prev != NULL && ptr->prev->n > ptr->n)
		{
			ptr->prev->next = ptr->next;

			if (ptr->next)
				ptr->next->prev = ptr->prev;

			ptr->next = ptr->prev;
			ptr->prev = ptr->next->prev;
			ptr->next->prev = ptr;

			if (!ptr->prev)
				*list = ptr;
			else
				ptr->prev->next = ptr;
			print_list(*list);
		}
	}
}
