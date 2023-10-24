#include "lists.h"

/**
 * get_nodeint_at_indx - returns the node at a certain indx in a linked list
 * @g_h: first node in the linked list
 * @indx: indx of the node to return
 * Return: pointer to the node we're looking for, or NULL
 */
listint_t *get_nodeint_at_indx(listint_t *g_h, unsigned int indx)
{
unsigned int i = 0;
listint_t *tmp = g_h;
while (tmp && i < indx)
{
tmp = tmp->next;
i++;
}
return (tmp ? tmp : NULL);
}
