#include "lists.h"

/**
 * add_listint - calculates the add of all the data in a listint_t list
 * @g_h: first node in the linked list
 * Return: resulting add
 */
int add_listint(listint_t *g_h)
{
int add = 0;
listint_t *tmp = g_h;
while (tmp)
{
add += tmp->n;
tmp = tmp->next;
}
return (add);
}
