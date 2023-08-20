#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * insert_node - inserts a number into a sorted listint_t linked list
 * @head: pointer to a pointer to the head of the list
 * @number: number to insert
 * Return: address of the new node or NULL if it failed
 */
listint_t *insert_node(listint_t **head, int number)
{
    listint_t *new_node = malloc(sizeof(listint_t));
    if (new_node == NULL)
        return NULL;

    new_node->n = number;
    new_node->next = NULL;

    if (*head == NULL || number < (*head)->n)
    {
        new_node->next = *head;
        *head = new_node;
        return new_node;
    }

    listint_t *current = *head;
    while (current->next != NULL && number > current->next->n)
    {
        current = current->next;
    }

    new_node->next = current->next;
    current->next = new_node;

    return new_node;
}
