#include "sort.h"
/**
 * bubble_sort - sort array elements from min to max value
 * @array: array
 * @size: Number of elements in the array.
 */
void bubble_sort(int *array, size_t size)
{

	size_t a, idx, ptr = 0;

	if (size < 2)
		return;

	for (a = 0; a < size; a++)
		for (idx = 0; idx < size - a - 1; idx++)
		{
			if (array[idx] > array[idx + 1])
			{
			ptr = array[idx];
			array[idx] = array[idx + 1];
			array[idx + 1] = ptr;
			print_array(array, size);
			}
		}
}
