#include "lists.h"

/**
 * check_cycle - checks if a linked list has a cycle in it
 * @list: the head of the linked list
 * Return: 0 if there is no cycle, 1 if there is a cycle
 */
int check_cycle(listint_t *list)
{
    listint_t *tortoise, *hare;

    if (!list)
        return (0);

    tortoise = list;
    hare = list;

    while (hare != NULL && hare->next != NULL)
    {
        tortoise = tortoise->next;
        hare = hare->next->next;

        if (tortoise == hare)
            return (1); /* cycle found */
    }

    return (0); /* no cycle */
}
