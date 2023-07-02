#include "sort.h"

/**
 * shell_sort - implements the shell sort algorithm.
 * @array: array to sort
 * @size: size of the array
 * Return: void
 */
void shell_sort(int *array, size_t size)
{
	size_t p, q, idx, n = 1;
	int tmp, min;

	if (!array || size < 2)
		return;

	while (n < size / 3 + 1)
		n = n * 3 + 1;

	while (n > 0)
	{
		for (p = 0; p < n; p++)
		{
			q = 1;
			while (q < size)
			{
				idx = q;
				min = array[q];
				while (idx < size)
				{
					if (array[idx] < min)
					{
						min = array[idx];
						tmp = array[q];
						array[q] = min;
						array[idx] = tmp;
					}
					idx += n;
				}
				q += n;
			}
		}
		n = (n - 1) / 3;
		print_array(array, size);
	}
}
