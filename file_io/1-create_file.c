#include "main.h"
#include <stdlib.h>

/**
 * create_file - Creates a file and writes text_content to it.
 * @filename: The name of the file to create.
 * @text_content: NULL-terminated string to write to the file.
 *
 * Description: If the file already exists, it is truncated.
 *              If text_content is NULL, an empty file is created.
 *              The file permissions are set to rw------- (0600).
 *
 * Return: 1 on success, -1 on failure.
 */
int create_file(const char *filename, char *text_content)
{
	int fd, wlen;
	size_t len = 0;

	if (filename == NULL)
		return (-1);

	/* Calculate length of text_content if it is not NULL */
	if (text_content != NULL)
	{
		while (text_content[len])
			len++;
	}

	/* Open the file with the specified flags and permissions */
	fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);
	if (fd == -1)
		return (-1);

	/* Write content to the file if there is any */
	if (len > 0)
	{
		wlen = write(fd, text_content, len);
		if (wlen != (int)len)
		{
			close(fd);
			return (-1);
		}
	}

	close(fd);
	return (1);
}
