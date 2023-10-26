#include "main.h"

/**
 * binary_to_uint - converts a binary number to unsigned int
 * @q: string containing the binary number
 * Return: the converted number
 */
unsigned int binary_to_uint(const char *q)
{
int i;
unsigned int dec_val = 0;
if (!q)
return (0);
for (i = 0; q[i]; i++)
{
if (q[i] < '0' || q[i] > '1')
return (0);
dec_val = 2 * dec_val + (q[i] - '0');
}
return (dec_val);
}
