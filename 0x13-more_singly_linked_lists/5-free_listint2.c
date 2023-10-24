#include "lists.h"

/**
 * free_listint2 - frees a given linked list
 * @head2: pointer to the given listint_t list to be freed 
 */
void free_listint2(listint_t **head2)
{
 listint_t *temp;

 if (head2 == NULL)
 return;

 while (*head2)
 {
 temp = (*head2)->next;
 free(*head2);
 *head2 = temp;
 }

 *head2 = NULL;
}
