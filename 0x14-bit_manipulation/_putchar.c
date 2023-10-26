#include "main.h"
#include <unistd.h>
/**
 * _putchar - writes the given character char to stdout
 * @char: The character to be printed to stdout
 * Return: On success 1.
 * On error, -1 is returned, and errnumber is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
