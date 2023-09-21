#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * stack_push - Push a value onto the stack.
 * @stack: A pointer to the top of the stack.
 * @value: The value to push.
 */
void stack_push(listint_t **stack, int value)
{
listint_t *new_node = malloc(sizeof(listint_t));

if (new_node == NULL)
{
perror("Failed to allocate memory for the stack node");
exit(EXIT_FAILURE);
}

new_node->n = value;
new_node->next = *stack;
*stack = new_node;
}

/**
 * stack_pop - Pop a value from the stack.
 * @stack: A pointer to the top of the stack.
 *
 * Return: The popped value.
 */
int stack_pop(listint_t **stack)
{

listint_t *top_node;
int value;

if (*stack == NULL)
{
perror("Stack is empty");
exit(EXIT_FAILURE);
}

top_node = *stack;
value = top_node->n;
*stack = top_node->next;
free(top_node);

return value;
}


/**
 * is_palindrome - Check if a singly linked list is a palindrome.
 * @head: A pointer to the head of the linked list.
 *
 * Return: 1 if it's a palindrome, 0 otherwise.
 */
int is_palindrome(listint_t **head)
{

listint_t *slow = *head, *fast = *head;
listint_t *stack = NULL;
int value;

if (*head == NULL || (*head)->next == NULL)
return (1);

while (fast != NULL && fast->next != NULL)
{
stack_push(&stack, slow->n);
slow = slow->next;
fast = fast->next->next;
}

if (fast != NULL)
slow = slow->next;

while (slow != NULL)
{
value = stack_pop(&stack);
if (slow->n != value)
return 0;
slow = slow->next;
}

return 1;
}
