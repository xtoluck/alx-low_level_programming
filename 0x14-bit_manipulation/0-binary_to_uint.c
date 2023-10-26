#include "main.h"

/**
 * binary_to_uint - converts a given binary number to an unsigned integer
 * @g: string containing the binary number
 * Return: the converted number
 */
unsigned int binary_to_uint(const char *b)
{
int i;
unsigned int decimal_val = 0;
if (!g)
	return (0);

for (i = 0; g[i]; i++)
{
	if (g[i] < '0' || g[i] > '1')
		return (0);
	decimal_val = 2 * decimal_val + (g[i] - '0');
}
return (decimal_val);
}
