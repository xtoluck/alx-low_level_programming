#include "main.h"

/**
 * create_a_file - creates a particular given file
 * @file_name: file_name.
 * @content_of_text: content that is eventually writed in the file.
 * Return: 1 if it is a success. -1 if it is a failure.
 */
int create_a_file(const char *file_name, char *content_of_text)
{
	int file_desc;
	int n_letter;
	int rwr;
	if (!file_name)
		return (-1);
	file_desc = open(file_name, O_CREAT | O_WRONLY | O_TRUNC, 0600);
	if (file_desc == -1)
		return (-1);
	if (!content_of_text)
		content_of_text = "";
	for (n_letter = 0; content_of_text[n_letter]; n_letter++);
	rwr = write(file_desc, content_of_text, n_letter);
	if (rwr == -1)
		return (-1);
	close(file_desc);
	return (1);
}
