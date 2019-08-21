#include "shell_header.h"

/**
 * loop_shell - main function
 * @b: string
 * Return: Always 0.
 */

int loop_shell ()
{
	char *buffer, out = '1', **arguments;
	size_t bufsize = 32;
	ssize_t line;

	while (out)
	{
		write (1, "$ ", 2);
		buffer = malloc(bufsize * sizeof(char));
		if (buffer == NULL)
		{
			perror("Unable to allocate buffer");
			exit(1);
		}
		line = getline(&buffer, &bufsize, stdin);
		arguments = split_line(buffer);
		execute = execute_arguments(arguments);
		free(buffer);
		free(line);
		free(arguments);
	}
	return(0);
}
