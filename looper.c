#include "shell_header"

/**
 * loop_shell - main function
 * @b: string
 * Return: Always 0.
 */

int loop_shell ()
{
	getline();
	split_line();
	execute_arguments();
	free();
	free();
	return (0);
}
