#include "binary_trees.h"

/**
 * binary_tree_node - function that creates a binary tree node
 * @parent: a pointer to the parent node of the node to create
 * @value: the value to put in the new node
 * return: a pointer to the new node, or NULL on failure
*/
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
    binary_tree_t *NewNode = malloc(sizeof(binary_tree_t));

    if (NewNode == NULL)
        return NULL;

    if (parent != NULL)
    {
        NewNode->parent = parent;
    }
    NewNode->n = value;

    return NewNode;
}
