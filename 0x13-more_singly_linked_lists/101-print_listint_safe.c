#include "lists.h"
#include <stdio.h>

size_t looped_listint_len(const listint_t *g_h);
size_t print_listint_safe(const listint_t *g_h);

/**
 * looped_listint_len - Counts the number of unique nodes
 * in a looped listint_t linked list.
 * @g_h: A pointer to the head of the listint_t to check.
 * Return: If the list is not looped - 0.
 * Otherwise - the number of unique nodes in the list.
 */
size_t looped_listint_len(const listint_t *g_h)
{
const listint_t *tortoise, *hare;
size_t nodes = 1;
if (g_h == NULL || head->next == NULL)
return (0);
tortoise = g_h->next;
hare = (g_h->next)->next;
while (hare)
{
if (tortoise == hare)
{
tortoise = g_h;
while (tortoise != hare)
{
nodes++;
tortoise = tortoise->next;
hare = hare->next;
}
tortoise = tortoise->next;
while (tortoise != hare)
{
nodes++;
tortoise = tortoise->next;
}
return (nodes);
}
tortoise = tortoise->next;
hare = (hare->next)->next;
}
return (0);
}

/**
 * print_listint_safe - Prints a listint_t list safely.
 * @g_h: A pointer to the head of the listint_t list.
 * Return: The number of nodes in the list.
 */
size_t print_listint_safe(const listint_t *g_h)
{
size_t nodes, index = 0;
nodes = looped_listint_len(g_h);
if (nodes == 0)
{
for (; g_h != NULL; nodes++)
{
printf("[%p] %d\n", (void *)g_h, head->n);
g_h = head->next;
}
}
else
{
for (index = 0; index < nodes; index++)
{
printf("[%p] %d\n", (void *)g_h, head->n);
g_h = head->next;
}
printf("-> [%p] %d\n", (void *)g_h, head->n);
}
return (nodes);
}
