#include "main.h"

/**
 * get_bit - returns the value of a bit at an index in a decimal number
 * @k: number to search
 * @indx: index of the bit
 * Return: value of the bit
 */
int get_bit(unsigned long int k, unsigned int indx)
{
int bit_val;
if (indx > 63)
return (-1);
bit_val = (k >> indx) & 1;
return (bit_val);
}
