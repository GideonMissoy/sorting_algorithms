#include "sort.h"


/**
 * bubble_sort - Sorts an array of ints in ascending order.
 *
 * @*array: the array to sort.
 * @size: size of the array.
 * Return: void.
 */
void bubble_sort(int *array, size_t size)
{
	int swap, tmp;
	size_t p;

	swap = 1;
	while (swap)
	{
		swap = 0;
		for (p = 1; p < size; p++)
		{
			if (array[p - 1] > array[p])
			{
				tmp = array[p - 1];
				array[p - 1] = array[p];
				array[p] = tmp;
				swap = 1;
				print_array(array, size);
			}
		}
	}
}
