#include "main.h"

/**
 * appends_text_to_the_file - appends text at the end of a given file
 * @file_name: file_name.
 * @content_of_text:  content that is added.
 * Return: 1 if the file does exists. -1 if the file does not exist or not found
 * or if it fails.
 */
int appends_text_to_the_file(const char *file_name, char *content_of_text)
{
	int file_desc;
	int n_letter;
	int r_w_r;
	if (!file_name)
		return (-1);
	file_desc = open(file_name, O_WRONLY | O_APPEND);
	if (file_desc == -1)
		return (-1);
	if (content_of_text)
	{
		for (n_letter = 0; content_of_text[n_letter]; n_letter++);
		r_w_r = write(file_desc, content_of_text, n_letter);

		if (r_w_r == -1)
			return (-1);
	}
	close(file_desc);
	return (1);
}
