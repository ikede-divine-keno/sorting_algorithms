#include "sort.h"

/**
 * swap_node - swapped the nodes in a list
 *
 * @list: first node in doubly linked list
 * @a: address of first node
 * @b: address of second node
 */
void swap_node(listint_t **list, listint_t *a, listint_t *b)
{
	if (!a->prev)	/* at the first node */
		*list = b;
	else
		a->prev->next = b;

	b->prev = a->prev;

	if (b->next)	/* at the last node */
		b->next->prev = a;

	a->prev = b;
	a->next = b->next;
	b->next = a;
}

/**
 * cocktail_sort_list - application of the cocktail sort algorithm
 * to sort numbers
 *
 * @list: first node of doubly linked list
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *ptr;
	int swapped_node = 1;

	if (!list || !(*list) || !(*list)->next)  /* only one node */
		return;

	ptr = *list;
	while (swapped_node)
	{
		swapped_node = 0;
		while (ptr->next)    /* traverse forward */
		{
			if (ptr->n > ptr->next->n)
			{
				swap_node(list, ptr, ptr->next);
				print_list(*list);
				swapped_node = 1;
				continue;
			}
			ptr = ptr->next;
		}

		if (!swapped_node)   /* list is sorted */
			break;

		swapped_node = 0;
		while (ptr->prev)    /* traverse backwards */
		{
			if (ptr->n < ptr->prev->n)
			{
				swap_node(list, ptr->prev, ptr);
				print_list(*list);
				swapped_node = 1;
				continue;
			}
			ptr = ptr->prev;
		}
	}
}  
