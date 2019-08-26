#include "shell_header.h"

/**
 * loop_shell - main function
 * @b: string
 * Return: Always 0.
 */
int loop_shell(void)
{
	char **args;
	int state;
	size_t num_characters;

	do
	{
		write (1, "$ ", 2);
		buffer = malloc(bufsize * sizeof(char));
		if (buffer == NULL)
		{
			perror("Unable to allocate buffer");
			exit(1);
		}
		num_characters = getline(&buffer, &bufsize, stdin);
		arguments = split_line(buffer);
		execute = execute_arguments(arguments, num_characters);
		free(buffer);
		free(num_characters);
		free(arguments);
	} while (state);
	return(0);
}
