#include "search_algos.h"

/**
 * print_array - Prints an array of integers
 * @array: The array to be printed
 * @size: The size of the array
 */
void print_array(int *array, size_t left, size_t right)
{
size_t i;
printf("Searching in array: ");
for (i = left; i <= right; i++)
{
printf("%d", array[i]);
if (i < right)
printf(", ");
}
printf("\n");
}

/**
 * binary_search_rec - Helper function to perform recursive binary search
 * @array: Pointer to the first element of the array to search in
 * @left: Left index of the subarray
 * @right: Right index of the subarray
 * @value: The value to search for
 * @return: The index where value is located or -1
 */
int binary_search_rec(int *array, size_t left, size_t right, int value)
{
size_t mid;
if (left > right)
{
return -1;
}

mid = left + (right - left) / 2;
print_array(array, left, right);

if (array[mid] == value)
{
if (mid == left || array[mid - 1] != value)
return mid;
else
right = mid;
}
else if (array[mid] < value)
{
left = mid + 1;
}
else
{
right = mid - 1;
}
return binary_search_rec(array, left, right, value);
}

/**
 * advanced_binary - Searches for a value in a sorted array of integers
 * @array: Pointer to the first element of the array to search in
 * @size: Number of elements in array
 * @value: The value to search for
 * @return: The index where value is located or -1
 */
int advanced_binary(int *array, size_t size, int value)
{
if (array == NULL || size == 0)
return -1;

return binary_search_rec(array, 0, size - 1, value);
}
