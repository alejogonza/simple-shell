#include "shell_header.h"

/**
 * loop_shell - main function
 * @b: string
 * Return: Always 0.
 */
int loop_shell(void)
{
	char **arguments, *buffer;
	int execute;
	size_t bufsize = TOK_BUFSIZE, num_size;

	do
	{
		write (1, "$ ", 2);
		buffer = malloc(bufsize * sizeof(char));
		if (buffer == NULL)
		{
			free(buffer);
			perror("Unable to allocate buffer");
			return ('\0');
		}
		num_size = getline(&buffer, &bufsize, stdin);
		arguments = split_line(buffer);
		execute = execute_arguments(arguments, num_size);
		free(buffer);
/*		free(bufsize);*/
		free(arguments);
	} while (execute);
	return(0);
}
