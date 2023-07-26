#include "sort.h"
/**
 * merger - A function that sorts the subarrays.
 * @down: Lower index.
 * @mid: Middle index.
 * @up: Higher index.
 * @res: Output data.
 * @src: Input data.
 */
void merger(size_t down, size_t mid, size_t up, int *res, int *src)
{
	size_t a = 0, b = 0, c = 0;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(src + down, mid - down);
	printf("[right]: ");
	print_array(src + mid, up - mid);
	a = down;
	b = mid;
	c = down;
		for (; c < up; c++)
		{
			if (a < mid && (b >= up || src[a] <= src[b]))
			{
				res[c] = src[a];
				a++;
			}
			else
			{
				res[c] = src[b];
				b++;
			}
		}
	printf("[Done]: ");
	print_array(res + down, up - down);
}

/**
 * merge_parse - A funtion that splits the array recursively.
 * @down: Lower index.
 * @up: Higher index.
 * @array: The array to sort.
 * @cpy: The copy of the array.
 */
void merge_parse(size_t down, size_t up, int *array, int *cpy)
{
	size_t mid = 0;

	if (up - down < 2)
		return;
	mid = (down + up) / 2;
	merge_parse(down, mid, array, cpy);
	merge_parse(mid, up, array, cpy);
	merger(down, mid, up, array, cpy);
	for (mid = down; mid < up; mid++)
		cpy[mid] = array[mid];
}

/**
 * merge_sort - A function that sorts an array using merge algorithm.
 * @array: The array to sort.
 * @size: The size of the array.
 */
void merge_sort(int *array, size_t size)
{
	size_t n = 0;
	int *cpy = NULL;

	if (array == NULL || size < 2)
		return;
	cpy = malloc(sizeof(int) * size);
	if (cpy == NULL)
		return;
	for (; n < size; n++)
		cpy[n] = array[n];
	merge_parse(0, size, array, cpy);
}
