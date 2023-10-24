#include "lists.h"

/**
 * free_listint - frees a linked list
 * @g_h: listint_t list to be freed
 */
void free_listint(listint_t *g_h)
{
listint_t *tmp;
while (g_h)
{
tmp = g_h->next;
free(g_h);
g_h = tmp;
}
}
