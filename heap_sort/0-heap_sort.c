#include "sort.h"

/**
 * swap - Swaps two integers in an array
 * @a: first integer
 * @b: second integer
 */
void swap(int *a, int *b)
{
int tmp = *a;
*a = *b;
*b = tmp;
}

/**
 * sift_down - Corrects a single violation of the heap
 *  property in a subtree's root
 * @array: array to sift down
 * @start: start index of the heap
 * @end: end index of the heap
 * @size: size of the array
 */
void sift_down(int *array, size_t start, size_t end, size_t size)
{
size_t root = start;
size_t child;
size_t to_swap;

while ((child = 2 * root + 1) <= end)
{
to_swap = root; /* Keeps track of child to swap with */

if (array[to_swap] < array[child])
to_swap = child;
if (child + 1 <= end && array[to_swap] < array[child + 1])
to_swap = child + 1;
        
if (to_swap == root)
{ /* If root holds max element */
return;
}
else
{
swap(&array[root], &array[to_swap]);
print_array(array, size);
root = to_swap; /* Follow the node to keep heapifying */ 
}
}
}

/**
 * heapify - Creates a max heap from an unordered array
 * @array: array to be heapified
 * @size: size of the array
 */
void heapify(int *array, size_t size)
{
ssize_t start = (size - 2) / 2; /*  Last parent node */

while (start >= 0)
{
sift_down(array, start, size - 1, size);
start--;
}
}

/**
 * heap_sort - Sorts an array of integers in ascending 
 * order using the Heap sort algorithm
 * @array: array to sort
 * @size: size of the array
 */
void heap_sort(int *array, size_t size)
{
size_t end;

if (size < 2)
{
return;
}

heapify(array, size);

end = size - 1;
while (end > 0)
{
swap(&array[end], &array[0]);
print_array(array, size);
end--;
sift_down(array, 0, end, size);
}
}
