#include "lists.h"

/**
 * pop_listint - deletes the g_h node of a linked list
 * @g_h: pointer to the first element in the linked list
 * Return: the data inside the elements that was deleted,
 * or 0 if the list is empty
 */
int pop_listint(listint_t **g_h)
{
listint_t *tmp;
int num;
if (!g_h || !*g_h)
return (0);
num = (*g_h)->n;
tmp = (*g_h)->next;
free(*g_h);
*g_h = tmp;
return (num);
}
