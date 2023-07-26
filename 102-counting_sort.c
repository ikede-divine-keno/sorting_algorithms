#include "sort.h"
/**
 * counting_sort - Sorts an array using the counting sort algorithm.
 * @array: array to sort.
 * @size: size of the array to sort.
 */
void counting_sort(int *array, size_t size)
{
	int *counter = NULL, cpy_arr[1024];
	unsigned int n, lim = 0;

	if (array == NULL || size < 2)
		return;
	for (n = 0; n < size; n++)
	{
		if (array[n] > (int)lim)
		lim = array[n];
		cpy_arr[n] = array[n];
	}
	lim++;
	counter = malloc(sizeof(int) * lim);
	if (!counter)
		return;
	for (n = 0; n < lim; n++)
		counter[n] = 0;
	for (n = 0; n < size; n++)
		counter[array[n]] = counter[array[n]] + 1;
	for (n = 0; n < lim; n++)
	{
		if (n != 0)
		counter[n] = counter[n] + counter[n - 1];
	}
	print_array((const int *)counter, lim);
	for (n = 0; n < size; n++)
	{
		array[counter[cpy_arr[n]] - 1] = cpy_arr[n];
		counter[cpy_arr[n]]--;
	}
	free(counter);
} 
