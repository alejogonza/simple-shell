#include "shell_header.h"

/**
 * split_line - function to split the line with tokens
 * @
 *
 * Return: Always 0.
 */

int split_line (char *buffer)
{
	char *token;

	token = strtok(buffer, " ");
	if (token == NULL)
		;
	return (token);
}
