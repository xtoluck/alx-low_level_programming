#include "lists.h"

/**
 * reverse_listint - reverses a linked list
 * @g_h: pointer to the first node in the list
 * Return: pointer to the first node in the new list
 */
listint_t *reverse_listint(listint_t **g_h)
{
listint_t *prev = NULL;
listint_t *next = NULL;
while (*g_h)
{
next = (*g_h)->next;
(*g_h)->next = prev;
prev = *g_h;
*g_h = next;
}
*g_h = prev;
return (*g_h);
}
