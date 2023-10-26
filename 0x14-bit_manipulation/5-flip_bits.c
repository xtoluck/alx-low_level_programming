#include "main.h"

/**
 * flip_bits - counts the number of bits to be changed
 * to get from one number to another
 * @i: first number
 * @j: second number
 * Return: number of bits to change
 */
unsigned int flip_bits(unsigned long int i, unsigned long int j)
{
int k, count = 0;
unsigned long int current;
unsigned long int exclusive = i ^ j;
for (k = 63; k >= 0; k--)
{
current = exclusive >> k;
if (current & 1)
count++;
}
return (count);
}
