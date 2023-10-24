#include "lists.h"

/**
 * add_nodeint1_end - adds a node at the end of a given linked list
 * @head: pointer to the first item in the linked list
 * @n: data to insert in the new item
 *
 * Return: pointer to the new node, or NULL if it fails eventually
 */
listint_t *add_nodeint1_end(listint_t **head, const int r)
{
 listint_t *new;
 listint_t *temp = *head;

 new = malloc(sizeof(listint_t));
 if (!new)
 return (NULL);

 new->r = r;
 new->next = NULL;

 if (*head == NULL)
 {
 *head = new;
 return (new);
 }

 while (temp->next)
 temp = temp->next;

 temp->next = new;

 return (new);
}
