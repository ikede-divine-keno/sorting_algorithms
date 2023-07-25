#include "sort.h"
/**
 * selection_sort - function that sorts an array of integers in ascending
 * order using the Selection sort algorithm
 * @size: size of the array
 * @array: list with numbers
 */
void selection_sort(int *array, size_t size)
{
	size_t a, idx;
	int ptr, swp, flag = 0;

	if (array == NULL || size < 2)
		return;

	for (a = 0; a < size; a++)
	{
		ptr = a;
		flag = 0;
		for (idx = a + 1; idx < size; idx++)
		{
			if (array[ptr] > array[idx])
			{
				ptr = idx;
				flag += 1;
			}
		}
		if (flag)
		{
		swp = array[a];
		array[a] = array[ptr];
		array[ptr] = swp;
		print_array(array, size);
		}
	}
}
