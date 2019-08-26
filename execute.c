#include "shell_header.h"

/**
 * _strcmp - check the code for Holberton School students.
 * @s1: string 1
 * @s2: string 2
 * Return: rest.
 */
int _strcmp(char *s1, char *s2)
{
	int rest = 0;

	while (*s1 == *s2 && *s1 != 0 && *s2 != 0)
	{
		s1++;
		s2++;
	}
	rest = *s1 - *s2;
	return (rest);
}

/**
 * execute_arguments - function to execute all arguments founded
 * @b: string
 * Return: Always 0.
 */
int execute_arguments(char **args, int num_characters)
{
	int i;

	if (args[0] == NULL)
		return 1;
	for (i = 0; i < num_characters; i++)
	{
		if (_strcmp(args[0], array_str[i]) == 0)
			return (*array_funciones[i])(args);
	}
	return hilos_programa(args);
}
