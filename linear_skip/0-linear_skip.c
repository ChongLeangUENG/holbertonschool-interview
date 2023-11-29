#include "search.h"
#include <math.h>

/**
 * linear_skip - Searches for a value 
 * in a sorted skip list of integers.
 * @list: Pointer to the head of the skip list.
 * @value: The value to search for.
 * 
 * Return: Pointer to the first node where value is located, or NULL.
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
    skiplist_t *express, *prev;

    if (!list)
        return (NULL);

    express = list->express;
    prev = list;
    while (express && express->n < value)
    {
        printf("Value checked at index [%lu] = [%d]\n", express->index, express->n);
        prev = express;
        if (!express->express)
            break;
        express = express->express;
    }

    if (!express)
        express = prev;
    while (express->next && express->n < value)
        express = express->next;

    printf("Value found between indexes [%lu] and [%lu]\n", prev->index, express->index);

    while (prev && prev->n < value)
        prev = prev->next;

    if (prev && prev->n == value)
        return (prev);

    return (NULL);
}
