#include <stdio.h>
#include <stdlib.h>

void merge(int *array, int *left, int leftCount, int *right, int rightCount)
{
int i = 0, j = 0, k = 0;

while (i < leftCount && j < rightCount)
{
if (left[i] < right[j])
{
    array[k++] = left[i++];
} else {
    array[k++] = right[j++];
}
}
while (i < leftCount)
{
array[k++] = left[i++];
}
while (j < rightCount)
{
array[k++] = right[j++];
}
}

void merge_sort(int *array, size_t size)
{
size_t i, mid;
int *left;
int *right;

if (size < 2) return;
mid = size / 2;
left = (int*)malloc(mid * sizeof(int));
right = (int*)malloc((size - mid) * sizeof(int));

for (i = 0; i < mid; i++)
{
left[i] = array[i];
}
for (i = mid; i < size; i++)
{
right[i - mid] = array[i];
}

merge_sort(left, mid);
merge_sort(right, size - mid);

merge(array, left, mid, right, size - mid);

free(left);
free(right);
}
