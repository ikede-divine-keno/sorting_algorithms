#include "sort.h"
/**
 * swap_node - the positions of two elements into an array
 * @array: array
 * @a: first element
 * @b: second element
 */
void swap_node(int *array, ssize_t a, ssize_t b)
{
	int ptr;

	ptr = array[a];
	array[a] = array[b];
	array[b] = ptr;
}
/**
 * hoare_partition - hoare partition sorting scheme implementation
 * @array: array
 * @first: first array element
 * @last: last array element
 * @size: size array
 * Return: return the position of the last element sorted
 */
int hoare_partition(int *array, int first, int last, int size)
{
	int current = first - 1, final = last + 1;
	int pivot = array[last];

	while (1)
	{

		do {
			current++;
		} while (array[current] < pivot);
		do {
			final--;
		} while (array[final] > pivot);
		if (current >= final)
			return (current);
		swap_node(array, current, final);
		print_array(array, size);
	}
}
/**
 * _quick_sort - qucksort algorithm implementation
 * @array: array
 * @first: first array element
 * @last: last array element
 * @size: array size
 */
void _quick_sort(int *array, ssize_t first, ssize_t last, int size)
{
	ssize_t idx = 0;

	if (first < last)
	{
		idx = hoare_partition(array, first, last, size);
		_quick_sort(array, first, idx - 1, size);
		_quick_sort(array, idx, last, size);
	}
}
/**
 *quick_sort_hoare - prepare the terrain to quicksort algorithm
 *@array: array
 *@size: array size
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	_quick_sort(array, 0, size - 1, size);
}
