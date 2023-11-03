#include "main.h"

/**
 * read_textfile - reads a given text file and then prints out the letters
 * @file_name: file_name.
 * @printed_letters: numbers of the letters that are printed out.
 * Return: The numbers of letters that are printed out.
 * If it eventually fails, returns 0.
 */
ssize_t read_textfile(const char *file_name, size_t printed_letters)
{
	int file_desc;
ssize_t n_r_d, n_w_r;
char *buf;
if (!file_name)
return (0);
file_desc = open(file_name, O_RDONLY);
if (file_desc == -1)
return (0);
buf = malloc(sizeof(char) * (printed_letters));
if (!buf)
return (0);
n_r_d = read(file_desc, buf, printed_letters);
n_w_r = write(STDOUT_FILENO, buf, n_r_d);
close(file_desc);
free(buf);
return (n_w_r);
}
