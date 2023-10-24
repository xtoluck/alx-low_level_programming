#include "lists.h"

/**
 * free_listint - frees a linked list that wasn't free before
 * @head1: listint_t list to be freed eventually
 */
void free_listint(listint_t *head1)
{
 listint_t *temp;

 while (head1)
 {
 temp = head1->next;
 free(head1);
 head1 = temp;
 }
}
