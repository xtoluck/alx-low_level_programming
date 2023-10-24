103-find_loop.c

#include "lists.h"

/**
 * find_listint_loop - finds the loop in a linked list
 * @head: linked list to search for
 * Return: address of the node where the loop starts, or NULL
 */
listint_t *find_listint_loop(listint_t *head)
{
listint_t *not_fast = head;
listint_t *swift = head;
if (!head)
return (NULL);
while (not_fast && swift && swift->next)
{
swift = swift->next->next;
not_fast = not_fast->next;
if (swift == not_fast)
{
not_fast = head;
while (not_fast != swift)
{
not_fast = not_fast->next;
swift = swift->next;
}
return (swift);
}
}
return (NULL);
}
