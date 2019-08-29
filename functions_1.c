#include "shell_header.h"

/**
 * function_cd - verify if argument is a existing directory,
 * @args: argument
 * if not have arguments ask for one
 * Return: always 1
 */

int function_cd(char **args)
{
/*      ask if argument is != to NULL */
	if (args[1] != NULL && args[1] != "")
	{
		if (chdir(args[1]) != 0)
			write(1, "Directory not found\n", 20);
	} else
		write(1, "Give one argument for cd\n", 25);
	return (1);
}

/**
 * function_exit - command exit
 * @args: arguments
 * Return: always 0
 */
int function_exit(char **args)
{
	return (0);
}

/**
 * stat_arguments - function to search if have executable in the path
 * @argpath: arguments concat
 * Return: Always 0.
 */
int stat_arguments(char *argpath)
{
	struct stat st;

	if (stat(argpath, &st) == 0)
		return (0);
	return (1);
}
