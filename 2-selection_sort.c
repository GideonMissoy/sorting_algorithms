#include "sort.h"


/**
 * selection_sort - Sorts an array of int in ascending
 * @array: the array to sort
 * @size: the size of the array
 * Return: 0
 */
void selection_sort(int *array, size_t size)
{
	int tmp, min;
	size_t p, q, idx;

	for (p = 0; p < size; p++)
	{
		min = array[p];
		idx = p;
		for (q = p+ 1; q < size; q++)
		{
			if (array[q] < min)
			{
				min = array[q];
				idx = q;
			}
		}
		if (min != array[p])
		{
			tmp = array[p];
			array[idx] = tmp;
			array[p] = min;
			print_array(array, size);
		}
	}
}
