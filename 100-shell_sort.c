#include "sort.h"

/**
 * knuth_seq - gets the max gap according the Knuth sequence
 *
 * @size: the size of the array
 *
 * Return: the max gap
 */

size_t knuth_seq(size_t size)
{
	size_t seq = 1;

	while (seq < size)
		seq = seq * 3 + 1;
	if (seq >= size)
		seq = (seq - 1) / 3;

	return (seq);
}

/**
 * shell_sort - sorts an array of integers using shell sort (Knuth sequence)
 *
 * @array: the array of integers
 * @size: the size of the array
 */

void shell_sort(int *array, size_t size)
{
	size_t seq = 0, a, b;
	int ptr;

	seq = knuth_seq(size);
	while (seq > 0)
	{
		for (a = seq; a < size; a++)
		{
			ptr = array[a];

			for (b = a; b >= seq && array[b - seq] > ptr; b -= seq)
				array[b] = array[b - seq];

			array[b] = ptr;
		}
		print_array(array, size);
		seq = (seq - 1) / 3;
  	}
}
