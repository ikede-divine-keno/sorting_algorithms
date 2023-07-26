#include "sort.h"
/**
 * swap_node - swaps position of values in array
 * @array: array to be changed
 * @a: first index
 * @b: second index
 */
void swap_node(int **array, int a, int b)
{
	int ptr;

	ptr = (*array)[a];
	(*array)[a] = (*array)[b];
	(*array)[b] = ptr;
}

/**
 * Max_Heap - builds a heap from an array
 * @array: array to be changed to heap array
 * @last_idx: end index as array is partitioned
 * @first_idx: starting point index as array is sorted
 * @size: array size unchanged
 */
void Max_Heap(int *array, int last_idx, int first_idx, int size)
{
	int max, left, right;

	max = first_idx;
	left = (first_idx * 2) + 1;
	right = (first_idx * 2) + 2;

	if (left < last_idx && array[left] > array[max])
		max = left;

	if (right < last_idx && array[right] > array[max])
		max = right;

	if (max != first_idx)
	{
		swap_node(&array, first_idx, max);
		print_array(array, size);
		Max_Heap(array, last_idx, max, size);
	}
}

/**
 * heap_sort - sorts an array using the Heap sort algorithm
 * @array: array to be sorted
 * @size: size of the array
 */
void heap_sort(int *array, size_t size)
{
	int first_idx, a;

	if (!array || size < 2)
		return;

	first_idx = ((int)size - 1) / 2;

	/*Build max heap*/
	for (a = first_idx; a >= 0; a--)
	{
		Max_Heap(array, size, a, size);
	}

	/*Destroy max heap and print sorted array*/
	for (a = size - 1; a > 0; a--)
	{
		swap_node(&array, 0, a);
		print_array(array, size);
		Max_Heap(array, a, 0, size);
	}
}
