#ifndef __MAIN_H__
#define __MAIN_H__

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

ssize_t read_textfile(const char *file_name, size_t letters);
int create_file(const char *file_name, char *content_of_text);
int append_text_to_file(const char *file_name, char *content_of_text);
#endif

