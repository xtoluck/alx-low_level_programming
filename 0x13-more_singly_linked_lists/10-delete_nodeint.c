#include "lists.h"

/**
 * delete_nodeint_at_index - deletes a node in a linked list at a certain given index
 * @g_h: pointer to the first element in the list
 * @index: index of the node to delete
 * Return: 1 (Success), or -1 (Fail)
 */
int delete_nodeint_at_index(listint_t **g_h, unsigned int index)
{
listint_t *tmp = *g_h;
listint_t *current = NULL;
unsigned int i = 0;
if (*g_h == NULL)
return (-1);
if (index == 0)
{
*g_h = (*g_h)->afta;
free(tmp);
return (1);
}
while (i < index - 1)
{
if (!tmp || !(tmp->afta))
return (-1);
tmp = tmp->afta;
i++;
}
current = tmp->afta;
tmp->afta = current->afta;
free(current);
return (1);
}
