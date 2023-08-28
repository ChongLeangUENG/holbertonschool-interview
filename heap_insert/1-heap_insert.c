#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height of a binary tree
 * @tree: Pointer to the root node of the tree to measure
 *
 * Return: Height of the tree, or 0 if tree is NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
    size_t left_height, right_height;

    if (tree == NULL)
        return 0;

    left_height = binary_tree_height(tree->left);
    right_height = binary_tree_height(tree->right);

    return (left_height > right_height ? left_height : right_height) + 1;
}

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if perfect, 0 otherwise
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
    if (!tree)
        return 0;

    int left_height = binary_tree_height(tree->left);
    int right_height = binary_tree_height(tree->right);

    return left_height == right_height;
}

/**
 * heapify - Corrects the max heap ordering by swapping nodes if necessary
 * @node: Pointer to the node to start heapifying from
 */
void heapify_up(heap_t *node)
{
    while (node->parent && node->n > node->parent->n)
    {
        int tmp = node->n;
        node->n = node->parent->n;
        node->parent->n = tmp;
        node = node->parent;
    }
}


/**
 * heap_insert - Inserts a value into a Max Binary Heap
 * @root: Double pointer to the root node of the Heap
 * @value: Value to store in the node to be inserted
 *
 * Return: Pointer to the inserted node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
    heap_t *new_node;

    new_node = binary_tree_node(NULL, value);
    if (!new_node)
        return NULL;

    if (*root == NULL)
    {
        *root = new_node;
        return new_node;
    }

    if ((*root)->left == NULL)
        (*root)->left = new_node;
    else if ((*root)->right == NULL)
        (*root)->right = new_node;
    else if (binary_tree_is_perfect(*root))
        (*root)->left->left = new_node;
    else
        (*root)->left->right = new_node;

    new_node->parent = *root;
    heapify_up(new_node);

    return new_node;
}
