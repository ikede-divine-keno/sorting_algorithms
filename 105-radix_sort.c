#include "sort.h"
/**
* get_max - A utility function to get maximum value in array[]
* @array: array
* @n: size of the array
* Return: array
*/
int get_max(int *array, int n)
{
	int a, max = array[0];

	for (a = 1; a < n; a++)
		if (array[a] > max)
			max = array[a];
	return (max);
}

/**
* count_sort - A function to do counting sort of arr[] according to
* the digit represented by exp.
* @array: array
* @n: size of the array
* @exp: exp is 10^i
* @res: array to save the temporary values
*/
void count_sort(int *array, size_t n, int exp, int *res)
{
	int a;
	int counter[10] = {0};

	/* Store count of occurrences in count[] */
	for (a = 0; a < (int)n; a++)
		counter[(array[a] / exp) % 10]++;

	/*
	* Change counter[a] so that counter[a] now contains actual
    * position of this digit in output[]
	*/
	for (a = 1; a < 10; a++)
		counter[a] += counter[a - 1];

	/* Build the output array */
	for (a = n - 1; a >= 0; a--)
	{
		res[counter[(array[a] / exp) % 10] - 1] = array[a];
		counter[(array[a] / exp) % 10]--;
	}

	/*
	* Copy the output array to array[], so that array[] now
    * contains sorted numbers according to current digit
	*/
	for (a = 0; a < (int)n; a++)
		array[a] = res[a];
	/*print_array(array, n);*/
}

/**
* radix_sort - The main function to that sorts arr[]
* of size n using Radix Sort
* @array: array
* @size: size of the array
*/
void radix_sort(int *array, size_t size)
{
	/* Find the maximum number to know number of digits */
	int exp, max = 0;
	int *res = NULL; /* output array should be n(size) */

	if (array == NULL || size < 2)
		return;

	max = get_max(array, size);
	res = malloc(size * sizeof(int));
	if (res == NULL)
		return;
	/*
	* Do counting sort for every digit. Note that instead
    * of passing digit number, exp is passed. exp is 10^i
    * where i is current digit number
	*/
	for (exp = 1; max / exp > 0; exp *= 10)
	{
		count_sort(array, size, exp, res);
		print_array(array, size);
	}
	free(res);
}
