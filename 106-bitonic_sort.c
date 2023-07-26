#include "sort.h"
/**
 * swap_cmp - compare and swap values based on dir
 *
 * @array: the array (or subarray) to sort
 * @dir: the direction of sorting
 * @size: the size of the array
 */

void swap_cmp(int *array, int dir, size_t size)
{
	size_t n, seq;
	int ptr;

	seq = size / 2;

	for (n = 0; n < seq; n++)
	{
		if ((array[n] > array[n + seq]) == dir)
		{
			ptr = array[n];
			array[n] = array[n + seq];
			array[n + seq] = ptr;
		}
	}

}

/**
 * bitonic_merge - recursively merge 2 "semibitonic" subarrays
 *
 * @array: the array (or subarray) to sort
 * @dir: the direction of sorting
 * @size: the size of the array
 */

void bitonic_merge(int *array, int dir, size_t size)
{
	size_t half = size / 2;

	if (size < 2)
		return;

	swap_cmp(array, dir, size);
	bitonic_merge(array, dir, half);
	bitonic_merge((array + half), dir, half);
}

/**
 * sort_bitonic - recursively sorts using bitonic algorithm
 *
 * @array: the array (or subarray) to sort
 * @dir: the direction of sorting
 * @size: size of the full array
 * @subsiz: the size of the subarray
 */

void sort_bitonic(int *array, int dir, size_t size, size_t subsiz)
{
	size_t half = (size / 2);

	if (size < 2)
		return;

	printf("Merging [%lu/%lu] (%s):\n", size, subsiz, (dir == 1) ? "UP" : "DOWN");
	print_array(array, size);
	sort_bitonic(array, 1, half, subsiz);
	sort_bitonic((array + half), 0, half, subsiz);
	bitonic_merge(array, dir, size);
	printf("Result [%lu/%lu] (%s):\n", size, subsiz, (dir == 1) ? "UP" : "DOWN");
	print_array(array, size);
}

/**
 * bitonic_sort - sorts an array of integers in ascending order using
 * the Bitonic sort algorithm
 *
 * @array: the array to sort
 * @size: size of the array
 */

void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	sort_bitonic(array, 1, size, size);
}
