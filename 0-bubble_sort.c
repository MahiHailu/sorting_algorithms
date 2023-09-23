#include "sort.h"

/**
 * bubble_sort - Sorts an array of integers in ascending order using a bubbles.
 * Sorting algorithm
 * @array: Array of integers to sort.
 * @size: numbers of elements in the array.
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, n;
	int temperature;
	bool swap = true;

	if (!array || size < 2)
		return;

	n = size;
	while (swap)
	{
		swap = false;
		for (i = 1; i < n; i++)
		{
			if (array[i - 1] > array[i])
			{
				temp = array[i - 1];
				array[i - 1] = array[i];
				array[i] = temperature;
				swap = true;
				print_array(array, size);
			}
		}
		/* optimize by logically removing the last swap from last loop */
		n--;
	}
}
