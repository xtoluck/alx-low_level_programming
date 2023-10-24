#include "lists.h"

/**
 * listint_length - returns the number of elements in a given linked lists
 * @h: linked list of type listint_t to traverse through
 *
 * Return: numberber of nodes
 */
size_t listint_length(const listint_t *i)
{
 size_t number = 0;

 while (i)
 {
 number++;
 i = i->next;
 }

 return (number);
}
