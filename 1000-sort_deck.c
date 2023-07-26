#include "deck.h"
#include <stdio.h>
/**
 * str_cmp - compare two strings
 * @str1: first string
 * @str2: second string
 * Return: 1 if str1 and str2 is equal, 0 if they are not equal
 */
int str_cmp(const char *str1, char *str2)
{
	size_t n = 0;

	if (str1 == NULL)
		return (0);
	while (str1[n])
	{
		if (str1[n] != str2[n])
			return (0);
		n++;
	}
	if (str1[n] == '\0' && str2[n])
		return (0);
	return (1);
}
/**
 * locate_card - return the position based on card you put in
 * @node: represent the card
 * Return: return the card position
 */
int locate_card(deck_node_t *node)
{
	int val;

	val = (*node).card->value[0] - '0';
	if (val < 50 || val > 57)
	{
		if (str_cmp((*node).card->value, "Ace") == 1)
			val = 1;
		else if (str_cmp((*node).card->value, "10") == 1)
			val = 10;
		else if (str_cmp((*node).card->value, "Jack") == 1)
			val = 11;
		else if (str_cmp((*node).card->value, "Queen") == 1)
			val = 12;
		else if (str_cmp((*node).card->value, "King") == 1)
			val = 13;
	}
	val += (*node).card->kind * 13;
	return (val);
}
/**
 *swap_cards - swap a card for his previous one
 *@card: card
 *@deck: card deck
 *Return: return a pointer to a card which was enter it
 */
deck_node_t *swap_cards(deck_node_t *card, deck_node_t **deck)
{
	deck_node_t *behind = card->prev, *current = card;

	behind->next = current->next;
	if (current->next)
		current->next->prev = behind;
	current->next = behind;
	current->prev = behind->prev;
	behind->prev = current;
	if (current->prev)
		current->prev->next = current;
	else
		*deck = current;
	return (current);
}

/**
 * insertion_sort_deck - function that sorts a doubly linked deck
 * of integers in ascending order using the Insertion sort algorithm
 * @deck: Dobule linked deck to sort
 */
void insertion_sort_deck(deck_node_t **deck)
{
	int val_prev, val_current;
	deck_node_t *node;

	if (deck == NULL || (*deck)->next == NULL)
		return;
	node = (*deck)->next;
	while (node)
	{
		/* preparing the previous value */
		if (node->prev)
		{
			val_prev = locate_card((node->prev));
			val_current = locate_card(node);
		}
		while ((node->prev) && (val_prev > val_current))
		{
			val_prev = locate_card((node->prev));
			val_current = locate_card(node);
			node = swap_cards(node, deck);

		}
		node = node->next;
	}
}
/**
 * sort_deck - sort a deck you put in using
 * insertion sort algorithm
 * @deck: deck
 */
void sort_deck(deck_node_t **deck)
{
	insertion_sort_deck(deck);
}
