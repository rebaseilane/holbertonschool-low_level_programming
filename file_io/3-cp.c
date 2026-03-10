#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

/**
 * error_exit_str - Prints an error message with a string argument and exits
 * @code: Exit code
 * @msg: Error message format
 * @arg: String argument to include
 */
void error_exit_str(int code, char *msg, char *arg)
{
	dprintf(STDERR_FILENO, msg, arg);
	exit(code);
}

/**
 * error_exit_int - Prints an error message with an integer argument and exits
 * @code: Exit code
 * @msg: Error message format
 * @arg: Integer argument to include
 */
void error_exit_int(int code, char *msg, int arg)
{
	dprintf(STDERR_FILENO, msg, arg);
	exit(code);
}

/**
 * main - Copies the content of a file to another file
 * @ac: Number of arguments
 * @av: Array of arguments
 *
 * Return: 0 on success
 *
 * Description: Usage: cp file_from file_to
 *              Reads 1024 bytes at a time
 *              Handles errors on open, read, write, and close
 */
int main(int ac, char **av)
{
	int fd_from, fd_to, r_bytes, w_bytes;
	char buffer[1024];

	if (ac != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	fd_from = open(av[1], O_RDONLY);
	if (fd_from == -1)
		error_exit_str(98, "Error: Can't read from file %s\n", av[1]);

	fd_to = open(av[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (fd_to == -1)
	{
		close(fd_from);
		error_exit_str(99, "Error: Can't write to %s\n", av[2]);
	}

	while ((r_bytes = read(fd_from, buffer, 1024)) > 0)
	{
		w_bytes = write(fd_to, buffer, r_bytes);
		if (w_bytes != r_bytes)
		{
			close(fd_from);
			close(fd_to);
			error_exit_str(99, "Error: Can't write to %s\n", av[2]);
		}
	}

	if (r_bytes == -1)
	{
		close(fd_from);
		close(fd_to);
		error_exit_str(98, "Error: Can't read from file %s\n", av[1]);
	}

	if (close(fd_from) == -1)
		error_exit_int(100, "Error: Can't close fd %d\n", fd_from);
	if (close(fd_to) == -1)
		error_exit_int(100, "Error: Can't close fd %d\n", fd_to);

	return (0);
}
