#include "shell_header.h"

/**
 * loop_shell - main function
 * @b: string
 * Return: Always 0.
 */
int loop_shell(void)
{
	char **arguments, *buffer, *getp, **argpath;
	int execute, i = 0, j = 0;
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
		buffer[num_size - 1] = '\0';
		arguments = split_line(buffer);
		getp = getpath("PATH=");
		argpath = malloc(bufsize * sizeof(char));
		argpath = split_line_path(getp);
		while (argpath[i] != '\0')
		{
			while(argpath[i][j] != '\0')
				j++;
			if (argpath[i][j] == '\0')
			{
				argpath[i][j] = '/';
				j++;
				argpath[i][j] = '\0';
			}
			_strcat(argpath[i], buffer);
			i = i + 2;
			j = 0;
		}
/*		execute = execute_arguments(arguments, num_size);*/
		free(buffer);
		free(arguments);
	} while (execute);
	return(0);
}
