#include "sort.h"

/**
 * swap_ptr - swaps position of elements in an array
 *
 * @i1: first element
 * @i2: second element
 */
void swap_ptr(int *i1, int *i2)
{
	int ptr;

	ptr = *i1;
	*i1 = *i2;
	*i2 = ptr;
}

/**
 * lomuto_partitioner - Order a subset of an array of integers according to
 *                    the lomuto partition scheme (last element as pivot).
 *
 * @array: array to be sorted
 * @front: lower boundary
 * @back: upper boundary
 * @size: size of the array
 *
 * Return: index of sorted pivot
 */
int lomuto_partitioner(int *array, size_t size, int front, int back)
{
	int *pivot, up, down;

	pivot = array + back;
	for (up = down = front; down < back; down++)
	{
		if (array[down] < *pivot)
		{
			if (up < down)
			{
				swap_ptr(array + down, array + up);
				print_array(array, size);
			}
			up++;
		}
	}
	if (array[up] > *pivot)
	{
		swap_ptr(array + up, pivot);
		print_array(array, size);
	}

	return (up);
}

/**
 * lomuto_sorter - Implement the quicksort algorithm through recursion.
 * @array: An array of integers to sort.
 * @size: The size of the array.
 * @up: The starting index of the array partition to order.
 * @down: The ending index of the array partition to order.
 *
 * Description: Uses the Lomuto partition scheme.
 */
void lomuto_sorter(int *array, size_t size, int up, int down)
{
	int part;

	if (down - up > 0)
	{
		part = lomuto_partitioner(array, size, up, down);
		lomuto_sorter(array, size, up, part - 1);
		lomuto_sorter(array, size, part + 1, down);
	}
}

/**
 * quick_sort - Sort an array of integers in ascending
 *              order using the quicksort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Uses the Lomuto partition scheme. Prints
 *              the array after each swap of two elements.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sorter(array, size, 0, size - 1);
}
