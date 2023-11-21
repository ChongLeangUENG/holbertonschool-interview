#include "binary_trees.h"

static avl_t *array_to_avl(int *array, int start, int end, avl_t *parent);

/**
 * array_to_avl - Helper function to create an AVL tree from a sorted array
 * @array: Pointer to the first element of the array
 * @start: Starting index of the sub-array
 * @end: Ending index of the sub-array
 * @parent: Pointer to the parent node
 *
 * Return: Pointer to the created AVL tree node
 */
static avl_t *array_to_avl(int *array, int start, int end, avl_t *parent)
{
    if (start > end)
        return NULL;

    int mid = (start + end) / 2;
    avl_t *node = malloc(sizeof(avl_t));
    if (!node)
        return NULL;

    node->n = array[mid];
    node->parent = parent;
    node->left = array_to_avl(array, start, mid - 1, node);
    node->right = array_to_avl(array, mid + 1, end, node);

    return node;
}

/**
 * sorted_array_to_avl - Converts a sorted array to an AVL tree
 * @array: Pointer to the first element of the array
 * @size: Number of elements in the array
 *
 * Return: Pointer to the root node of the AVL tree, or NULL on failure
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
    if (!array || size == 0)
        return NULL;

    return array_to_avl(array, 0, size - 1, NULL);
}
