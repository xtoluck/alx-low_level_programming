
#include "lists.h"
#include <stdio.h>

size_t looped_listint_len(const listint_t *t_start);
size_t print_listint_safe(const listint_t *t_start);

/**
 * looped_listint_len - Counts the number of unique nodes
 * in a looped listint_t linked list.
 * @t_start: A pointer to the t_start of the listint_t to check.
 * Return: If the list is not looped - 0.
 * Otherwise - the number of unique nodes in the list.
 */
size_t looped_listint_len(const listint_t *t_start)
{
const listint_t *tortoise, *j;
size_t nodes = 1;
if (t_start == NULL || t_start->next == NULL)
return (0);
tortoise = t_start->next;
j = (t_start->next)->next;
while (j)
{
if (tortoise == j)
{
tortoise = t_start;
while (tortoise != j)
{
nodes++;
tortoise = tortoise->next;
j = j->next;
}
tortoise = tortoise->next;
while (tortoise != j)
{
nodes++;
tortoise = tortoise->next;
}
return (nodes);
}
tortoise = tortoise->next;
j = (j->next)->next;
}
return (0);
}

/**
 * print_listint_safe - Prints a listint_t list safely.
 * @t_start: A pointer to the t_start of the listint_t list.
 * Return: The number of nodes in the list.
 */
size_t print_listint_safe(const listint_t *t_start)
{
size_t nodes, index = 0;
nodes = looped_listint_len(t_start);
if (nodes == 0)
{
for (; t_start != NULL; nodes++)
{
printf("[%p] %d\n", (void *)t_start, t_start->n);
t_start = t_start->next;
}
}
else
{
for (index = 0; index < nodes; index++)
{
printf("[%p] %d\n", (void *)t_start, t_start->n);
t_start = t_start->next;
}
printf("-> [%p] %d\n", (void *)t_start, t_start->n);
}
return (nodes);
}
