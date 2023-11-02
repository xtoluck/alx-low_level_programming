#include "main.h"
/**
 * appends_text_to_the_file - appends text at the end of a given file
 * @file_name: file_name.
 * @content_of_text:  content that is added.
 * Return: 1 if the file does exists.
 * -1 if the file does not exist or not found
 * or if it fails.
 */
int appends_text_to_the_file(const char *file_name, char *content_of_text)
{
	int fd;
	int nletters;
	int rwr;

	if (!file_name)
		return (-1);

	fd = open(file_name, O_WRONLY | O_APPEND);

	if (fd == -1)
		return (-1);

	if (content_of_text)
	{
		for (n_letters = 0; content_of_text[n_letters]; n_letters++)
			;

		rwr = write(fd, content_of_text, n_letters);

		if (rwr == -1)
			return (-1);
	}

	close(fd);

	return (1);
}
