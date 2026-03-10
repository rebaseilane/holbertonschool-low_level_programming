#include "main.h"
#include <fcntl.h>
#include <stdlib.h>

/**
 * read_textfile - Reads a text file and prints it to STDOUT.
 * @filename: Name of the file to read.
 * @letters: Number of letters to read and print.
 *
 * Return: The actual number of letters read and printed.
 *         0 if file cannot be opened, read, or write fails.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
    int fd;
    ssize_t r_bytes, w_bytes;
    char *buffer;

    if (!filename)
        return (0);

    fd = open(filename, O_RDONLY);
    if (fd == -1)
        return (0);

    buffer = malloc(sizeof(char) * letters);
    if (!buffer)
    {
        close(fd);
        return (0);
    }

    r_bytes = read(fd, buffer, letters);
    if (r_bytes == -1)
    {
        free(buffer);
        close(fd);
        return (0);
    }

    w_bytes = write(STDOUT_FILENO, buffer, r_bytes);
    free(buffer);
    close(fd);

    if (w_bytes != r_bytes)
        return (0);

    return (w_bytes);
}
