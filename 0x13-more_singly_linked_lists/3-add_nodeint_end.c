#include "lists.h"

/**
 * add_nodeint_end - adds a node at the end of a linked list
 * @g_h: pointer to the first element in the list
 * @n: data to insert in the new element
 * Return: pointer to the new node, or NULL if it fails
 */
listint_t *add_nodeint_end(listint_t **g_h, const int n)
{
listint_t *new;
listint_t *tmp = *g_h;
new = malloc(sizeof(listint_t));
if (!new)
return (NULL);
new->n = n;
new->next = NULL;
if (*g_h == NULL)
{
*g_h = new;
return (new);
}
while (tmp->next)
tmp = temp->next;
tmp->next = new;
return (new);
}
