#include "sort.h"

/**
 * get_maxv - Get the max value in an array of ints.
 * @array: array of ints
 * @size: size of the array
 * Return: The max integer in array.
 */
int get_maxv(int *array, int size)
{
	int max, q;

	for (max = array[0], q = 1; y < size; q++)
	{
		if (array[y] > max)
			max = array[y];
	}
	return (max);
}

/**
 * counting_sort - Sort an array of integers in ascending order
 * @array: An array of ints
 * @size: The size of the array
 * Return: Print array
 */
void counting_sort(int *array, size_t size)
{
	int *cnt, *srt, max, p;

	if (array == NULL || size < 2)
		return;

	srt = malloc(sizeof(int) * size);
	if (srt == NULL)
		return;
	max = get_maxv(array, size);
	cnt = malloc(sizeof(int) * (max + 1));
	if (cnt == NULL)
	{
		free(srt);
		return;
	}

	for (p = 0; p < (max + 1); p++)
		cnt[p] = 0;
	for (p = 0; p < (int)size; p++)
		cnt[array[p]] += 1;
	for (p = 0; p < (max + 1); p++)
		cnt[p] += cnt[p - 1];
	print_array(cnt, max + 1);

	for (p = 0; p < (int)size; p++)
	{
		srt[cnt[array[p]] - 1] = array[p];
		cnt[array[p]] -= 1;
	}

	for (p = 0; p < (int)size; p++)
		array[p] = srt[p];

	free(srt);
	free(cnt);
}
