#include "sort.h"


/**
 * print_array_from - Prints an array of integers
 *
 * @array: Array to be printed
 * @size: Num of elements in @array
 * @start: print start index
 */
void print_array_from(const int *array, size_t size, size_t start)
{
	size_t i;

	i = start;
	while (array && i < size)
	{
		if (i > start)
			printf(", ");
		printf("%d", array[i]);
		++i;
	}
	printf("\n");
}

/**
 * merge - merge two subarrays in sorted manner
 * @array: Array to b sorte
 * @left: Start of the subarray
 * @mid: Middle element of sub array
 * @right: End index of subarry
 * @temp_arr: the temp array to store in
 * Return: void
*/
void merge(int *array, size_t left, size_t mid, size_t right, int *temp_arr)
{
	size_t i = left, j = mid, k = left;

	printf("Merging...\n");
	printf("[left]: ");
	print_array_from(array, mid, left);
	printf("[right]: ");
	print_array_from(array, right, mid);
	while (i < mid && j < right)
	{
		if (array[i] <= array[j])
		{
			temp_arr[k] = array[i];
			i++;
		}
		else
		{
			temp_arr[k] = array[j];
			j++;
		}
		k++;
	}
	while (i < mid)
	{
		temp_arr[k] = array[i];
		i++;
		k++;
	}
	while (j < right)
	{
		temp_arr[k] = array[j];
		j++;
		k++;
	}
	for (k = left; k < right; k++)
		array[k] = temp_arr[k];
	printf("[Done]: ");
	print_array_from(array, right, left);

}
/**
 * merge_sorting - Implements merge sort algorithm
 * @array: Array to sort
 * @left: starting index of subarray
 * @right: End index of sub array (excluded)
 * @temp_arr: Temporary array to store results
 * Return: void
 *
*/
void merge_sorting(int *array, size_t left, size_t right, int *temp_arr)
{
	int mid;

	if (left + 1 >= right)
		return;

	mid = left + (right - left) / 2;
	merge_sorting(array, left, mid, temp_arr);
	merge_sorting(array, mid, right, temp_arr);
	merge(array, left, mid, right, temp_arr);

}

/**
 * merge_sort - Merge sort wrapping function
 * @array: Array to sort
 * @size: Size of array
 * Reutrn: void
*/
void merge_sort(int *array, size_t size)
{
	int *temp_arr;

	temp_arr = malloc(size * sizeof(int));
	if (temp_arr == NULL)
		return;
	merge_sorting(array, 0, size, temp_arr);
	free(temp_arr);
}
