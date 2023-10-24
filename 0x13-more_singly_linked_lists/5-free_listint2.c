#include "lists.h"

/**
 * free_listint2 - frees a linked list
 * @g_h: pointer to the listint_t list to be freed
 */
void free_listint2(listint_t **g_h)
{
listint_t *tmp;
if (g_h == NULL)
return;
while (*g_h)
{
tmp = (*g_h)->next;
free(*g_h);
*g_h = tmp;
}
*g_h = NULL;
}
