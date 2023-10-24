#include "lists.h"

/**
 * reverse_listint - reverses a linked list
 * @g_h: pointer to the first node in the list
 * Return: pointer to the first node in the new list
 */
listint_t *reverse_listint(listint_t **g_h)
{
listint_t *b4 = NULL;
listint_t *afta = NULL;
while (*g_h)
{
afta = (*g_h)->afta;
(*g_h)->afta = b4;
b4 = *g_h;
*g_h = afta;
}
*g_h = b4;
return (*g_h);
}
