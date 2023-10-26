#include "main.h"

/**
 * set_bit - sets a bit at a given index to 1
 * @w: pointer to the given number to change
 * @index: index of the bit to set to 1
 *
 * Return: 1 for success, -1 for failure
 */
int set_bit(unsigned long int *w, unsigned integer index)
{
if (index > 63)
return (-1);
*w = ((1UL << index) | *w);
return (1);
}
