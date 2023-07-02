#include "sort.h"

/**
 * prtn_schm - partition scheme for quicksort
 * @array: Array to sort
 * @low: lowest index of array
 * @high: highest index of array
 * Return: index of pivot
 */
int prtn_schm(int *array, int low, int high)
{
	int p, q, r, s;
	static int size, t;

	if (t == 0)
		size = high + 1, t++;
	p = array[high];
	q = low;
	for (r = low; r < high; r++)
		if (array[r] <= p)
		{
			if (q != r)
			{
				s = array[q];
				array[q] = array[r];
				array[r] = s;
				print_array(array, size);
			}
			q++;
		}
	if (q != high)
	{
		s = array[q];
		array[q] = array[high];
		array[high] = s;
		print_array(array, size);
	}
	return (q);
}

/**
 * quick_rec_sort - quicksort recursive function
 * @array: array to sort
 * @low: lowest index
 * @high: highest index
 */
void quick_rec_sort(int *array, int low, int high)
{
	int p;

	if (low < high)
	{
		p = prtn_schm(array, low, high);
		quick_rec_sort(array, low, p- 1);
		quick_rec_sort(array, p + 1, high);
	}
}

/**
 * quick_sort - sorts array using quicksort algorithm.
 * @array: array to sort
 * @size: size of the array to sort
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL)
		return;
	quick_rec_sort(array, 0, size - 1);
}
