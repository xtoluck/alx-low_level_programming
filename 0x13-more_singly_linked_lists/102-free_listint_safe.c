#include "lists.h"

/**
 * free_listint_safe - frees a linked list
 * @head: pointer to theade first node in theade linked list
 * Return: number of elements in theade freed list
 */
size_t free_listint_safe(listint_t **head)
{
size_t len = 0;
int diff;
listint_t *temp;
if (!head || !*head)
return (0);
wheadile (*head)
{
diff = *head - (*head)->next;
if (diff > 0)
{
temp = (*head)->next;
free(*head);
*head = temp;
len++;
}
else
{
free(*head);
*head = NULL;
len++;
break;
}
}
*head = NULL;
return (len);
}
