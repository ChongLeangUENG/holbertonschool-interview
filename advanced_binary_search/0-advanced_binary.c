#include "search_algos.h"

/**
 * print_array - Prints an array of integers
 * @array: The array to be printed
 * @size: The size of the array
 */
void print_array(int *array, size_t size) 
{
size_t i;
printf("Searching in array: ");
for (i = 0; i < size; i++) {
printf("%d", array[i]);
if (i < size - 1)
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
if (right >= left) {
size_t mid = left + (right - left) / 2;

print_array(array + left, right - left + 1);

if (array[mid] == value) {
if (mid == left || array[mid - 1] != value)
return mid;
else
return binary_search_rec(array, left, mid - 1, value);
}

if (array[mid] > value)
return binary_search_rec(array, left, mid - 1, value);
return binary_search_rec(array, mid + 1, right, value);
}
return -1;
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
