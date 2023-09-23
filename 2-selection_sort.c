#include "sort.h"

/**
 * swap_ints - Swap two integers in an array.
 * @array: Array of integers to sort.
 * @s: number of elements in the array
 */
void selection_sort(int *array, size_t size)
{
	int i, j, min_j, temp, n = (int)size;

	if (!array || size < 2)
		return;

	/* Any position in the n-member array */
	for (i = 0; i < n - 1; i++)
	{
		/* scan from this  position to the end, */
		min_j = i;
		for (j = i + 1; j < n; j++)
		{
			/* Determine the minimum value of this range */
			if (array[j] < array[min_j])
			{
				min_j = j;
			}
		}
		/* and if it is lower than the value at start of range, */
		/* swap them */
		if (min_j != i)
		{
			temp = array[i];
			array[i] = array[min_j];
			array[min_j] = temp;
			print_array(array, size);
		}
	}
}
