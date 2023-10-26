#include "main.h"

/**
 * clear_bit - sets the value of a given bit to 0
 * @k: pointer to the number to change
 * @indx: index of the bit to clear
 * Return: 1 for success, -1 for failure
 */
int clear_bit(unsigned long int *k, unsigned int indx)
{
if (indx > 63)
return (-1);
*k = (~(1UL << indx) & *k);
return (1);
}
