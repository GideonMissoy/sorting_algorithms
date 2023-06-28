#include "sort.h"


/**
 * swap - swaps 2 elements in the array
 * @a: first element
 * @b: second element
 */
void swap(int *a, int*b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * partition - partitions the array around a pivot element
 * @array: array to sort
 * @low: low
 * @high: high
 */
int partition(int *array, int low, int high)
{
	int pivot = array[high];
	int i = low - 1;

	for (int j = low; j < high; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			swap(&array[i], &array[j]);
		}
	}
	swap(&array[i + 1], &array[high]);
	return i + 1;
}

/**
 * quick_sort_recursive - performs the recursive steps
 * @array: array to sort
 * @low: low
 * @high: high
 */
void quick_sort_recursive(int *array, int low, int high)
{
	if (low < high)
	{
		int pivot = partition(array, low, high);
		quick_sort_recursive(array, low, pivot - 1);
		quick_sort_recursive(array, pivot + 1, high);
	}
}

/**
 * quick_sort - handle edge cases
 * @array: array to sort
 * @size: size of array to sort
 */
void quick_sort(int  *array, size_t size)
{
	if (array == NULL || size <= 1)
		return;

	quick_sort_recursive(array, 0, size - 1);
}
