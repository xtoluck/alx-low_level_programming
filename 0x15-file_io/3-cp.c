#include "main.h"
#include <stdio.h>

/**
 * error_file - checks if files can be opened.
 * @fileFrom: fileFrom.
 * @fileTo: fileTo.
 * @argVec: arguments vector.
 * Return: no return.
 */
void error_file(int fileFrom, int fileTo, char *argVec[])
{
	if (fileFrom == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argVec[1]);
		exit(98);
	}
	if (fileTo == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argVec[2]);
		exit(99);
	}
}

/**
 * main - checks the particular code for the given Holberton School students.
 * @arg_C: number of the given arguments.
 * @argVec: The given arguments vector.
 * Return: Always 0.
 */
int main(int arg_C, char *argVec[])
{
	int fileFrom, fileTo, err_close;
	ssize_t n_chars, n_w_r;
	char b_u_f[1024];

	if (arg_C != 3)
	{
		dprintf(STDERR_FILENO, "%s\n", "Usage: cp fileFrom fileTo");
		exit(97);
	}
	fileFrom = open(argVec[1], O_RDONLY);
	fileTo = open(argVec[2], O_CREAT | O_WRONLY | O_TRUNC | O_APPEND, 0664);
	error_file(fileFrom, fileTo, argVec);
	n_chars = 1024;
	while (n_chars == 1024)
	{
		n_chars = read(fileFrom, b_u_f, 1024);
		if (n_chars == -1)
			error_file(-1, 0, argVec);
		n_w_r = write(fileTo, b_u_f, n_chars);
		if (n_w_r == -1)
			error_file(0, -1, argVec);
	}
	err_close = close(fileFrom);
	if (err_close == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fileFrom);
		exit(100);
	}
	err_close = close(fileTo);
	if (err_close == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fileFrom);
		exit(100);
	}
	return (0);
}
