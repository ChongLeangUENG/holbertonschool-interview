#include "search_algos.h"
#include <stdio.h>

/**
 * print_array - Prints an array of integers
 * @array: The array to be printed
 * @size: The size of the array
 */
void print_array(int *array, size_t size) {
    printf("Searching in array: ");
    for (size_t i = 0; i < size; i++) {
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
int binary_search_rec(int *array, size_t left, size_t right, int value) {
    if (right >= left) {
        size_t mid = left + (right - left) / 2;

        // Print current subarray
        print_array(array + left, right - left + 1);

        // Check if the middle element is the value
        if (array[mid] == value) {
            // Check if it's the first occurrence
            if (mid == left || array[mid - 1] != value)
                return mid;
            else
                return binary_search_rec(array, left, mid - 1, value);
        }

        // If the value is smaller than mid, search in the left subarray
        if (array[mid] > value)
            return binary_search_rec(array, left, mid - 1, value);

        // Otherwise, the value is in the right subarray
        return binary_search_rec(array, mid + 1, right, value);
    }

    // Value not found
    return -1;
}

/**
 * advanced_binary - Searches for a value in a sorted array of integers
 * @array: Pointer to the first element of the array to search in
 * @size: Number of elements in array
 * @value: The value to search for
 * @return: The index where value is located or -1
 */
int advanced_binary(int *array, size_t size, int value) {
    if (array == NULL || size == 0)
        return -1;
    
    return binary_search_rec(array, 0, size - 1, value);
}
