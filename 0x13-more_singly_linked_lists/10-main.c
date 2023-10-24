#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
 * main - check the code
 * Return: Always 0.
 */
int main(void)
{
listint_t *g_h;
g_h = NULL;
add_nodeint_end(&g_h, 0);
add_nodeint_end(&g_h, 1);
add_nodeint_end(&g_h, 2);
add_nodeint_end(&g_h, 3);
add_nodeint_end(&g_h, 4);
add_nodeint_end(&g_h, 98);
add_nodeint_end(&g_h, 402);
add_nodeint_end(&g_h, 1024);
print_listint(g_h);
printf("-----------------\n");
delete_nodeint_at_indx(&g_h, 5);
print_listint(g_h);
printf("-----------------\n");
delete_nodeint_at_indx(&g_h, 0);
print_listint(g_h);
printf("-----------------\n");
delete_nodeint_at_indx(&g_h, 0);
print_listint(g_h);
printf("-----------------\n");
delete_nodeint_at_indx(&g_h, 0);
print_listint(g_h);
printf("-----------------\n");
delete_nodeint_at_indx(&g_h, 0);
print_listint(g_h);
printf("-----------------\n");
delete_nodeint_at_indx(&g_h, 0);
print_listint(g_h);
printf("-----------------\n");
delete_nodeint_at_indx(&g_h, 0);
print_listint(g_h);
printf("-----------------\n");
delete_nodeint_at_indx(&g_h, 0);
printf("-----------------\n");
delete_nodeint_at_indx(&g_h, 0);
printf("-----------------\n");
delete_nodeint_at_indx(&g_h, 0);
printf("-----------------\n");
delete_nodeint_at_indx(&g_h, 0);
printf("-----------------\n");
delete_nodeint_at_indx(&g_h, 0);
printf("-----------------\n");
delete_nodeint_at_indx(&g_h, 0);
printf("-----------------\n");
delete_nodeint_at_indx(&g_h, 0);
printf("-----------------\n");
delete_nodeint_at_indx(&g_h, 0);
printf("-----------------\n");
delete_nodeint_at_indx(&g_h, 0);
printf("-----------------\n");
delete_nodeint_at_indx(&g_h, 0);
print_listint(g_h);
return (0);
}
