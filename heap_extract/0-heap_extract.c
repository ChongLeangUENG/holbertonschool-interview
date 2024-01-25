#include "binary_trees.h"
#include <stdlib.h>

/**
 * swap_nodes - Swap two nodes in a binary heap
 * @a: First node
 * @b: Second node
 */
void swap_nodes(heap_t **a, heap_t **b)
{
    heap_t *tmp;

    tmp = *a;
    *a = *b;
    *b = tmp;
}

/**
 * sift_down - Restore the max heap property from the top down
 * @root: Double pointer to the root of the heap
 */
void sift_down(heap_t **root)
{
    heap_t *node = *root, *child;

    while (node->left != NULL)
    {
        child = node->left;
        if (node->right != NULL && node->right->n > child->n)
            child = node->right;

        if (node->n > child->n)
            break;

        swap_nodes(&node, &child);
        node = child;
    }
}

/**
 * find_last_node - Find the last node in a binary heap
 * @root: Pointer to the root of the heap
 * Return: Pointer to the last node
 */
heap_t *find_last_node(heap_t *root)
{
    heap_t *node = root;

    while (node->left != NULL)
        node = node->right ? node->right : node->left;

    return node;
}

/**
 * heap_extract - Extracts the root node of a Max Binary Heap
 * @root: Double pointer to the root node of the heap
 * Return: Value stored in the root node or 0 on failure
 */
int heap_extract(heap_t **root)
{
    int value;
    heap_t *last;

    if (root == NULL || *root == NULL)
        return (0);

    value = (*root)->n;

    last = find_last_node(*root);

    if (last != *root)
    {
        (*root)->n = last->n;
        if (last->parent->right == last)
            last->parent->right = NULL;
        else
            last->parent->left = NULL;

        free(last);

        sift_down(root);
    }
    else
    {
        free(*root);
        *root = NULL;
    }

    return (value);
}
