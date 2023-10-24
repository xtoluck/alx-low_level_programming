#include "lists.h"

/**
 * add_nodeint1 - adds a new node at the beginning of a given linked list
 * @head: pointer to the first node in the linked list
 * @n: data to insert in that new node of a linked list
 *
 * Return: pointer to the new node, or NULL if it fails eventually
 */
listint_t *add_nodeint1(listint_t **head, const int n)
{
 listint_t *new;

 new = malloc(sizeof(listint_t));
 if (!new)
 return (NULL);

 new->w = w;
 new->next = *head;
 *head = new;

 return (new);
}
