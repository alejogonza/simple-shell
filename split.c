#include "shell_header.h"

/**
 * *_realloc - prints buffer in hexa
 * @ptr: pointer
 * @old_size: size old
 * @new_size: size new
 * Return: ptr
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{

	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return ('\0');
	}

	if (new_size == old_size)
		return (ptr);

	if (ptr == NULL)
		ptr = malloc(new_size);

	free(ptr);
	ptr = malloc(new_size);
	return (ptr);
}

/**
 * split_line - function to split the line with tokens
 * @buffer: Line of arguments
 * Return: tokens
 */

char **split_line (char *buffer, char *tok)
{
	char *token, **tokens, **back_tokens;
	int posicion = 0, oldsize, newsize, bufsize = TOK_BUFSIZE;

	tokens = malloc(TOK_BUFSIZE * sizeof(char*));
	if (tokens == NULL)
	{
		perror("Error creating malloc");
		exit(98);
	}
	token = strtok(buffer, tok);
	while (token != NULL)
	{
		tokens[posicion] = token;
		posicion++;
		if (posicion >= bufsize)
		{
		bufsize += TOK_BUFSIZE;
		back_tokens = tokens;
		newsize = bufsize * sizeof(char*);
		oldsize = (bufsize - TOK_BUFSIZE) * sizeof(char*);
		tokens = _realloc(tokens, oldsize, newsize);
		if (!tokens)
			{
				free(back_tokens);
				perror("Error in realloc");
				exit (98);
			}
		}
		token = strtok(NULL, TOK_DELIM);
	}
	tokens[posicion] = NULL;
	return (tokens);
}
