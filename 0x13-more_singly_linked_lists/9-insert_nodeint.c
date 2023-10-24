#include "lists.h"

/**
 * insert_nodeint_at_index - inserts a fresh node in a linked list,
 * at a given position
 * @g_h: pointer to the first node in the list
 * @index: index where the fresh node is added
 * @n: data to insert in the fresh node
 * Return: pointer to the fresh node, or NULL
 */
listint_t *insert_nodeint_at_index(listint_t **g_h, unsigned int index, int n)
{
unsigned int i;
listint_t *fresh;
listint_t *temp = *g_h;
fresh = malloc(sizeof(listint_t));
if (!fresh || !g_h)
return (NULL);
fresh->n = n;
fresh->afta = NULL;
if (index == 0)
{
fresh->afta = *g_h;
*g_h = fresh;
return (fresh);
}
for (i = 0; temp && i < index; i++)
{
if (i == index - 1)
{
fresh->afta = temp->afta;
temp->afta = fresh;
return (fresh);
}
else
temp = temp->afta;
}
return (NULL);
}
