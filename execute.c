#include "shell_header.h"
extern char** environ;

/**
 * _strcmp - comparison between strings
 * @s1: string 1
 * @s2: string 2
 * Return: rest type int.
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
 * getpath - function to have the PATH line from env
 * Return: rest type int.
 */
char *getpath(void)
{
	int i = 0, j = 0, count = 0, breaker = 0;
	char *looking = "PATH";

	while (environ[i] != NULL)
	{
		for (j = 0; environ[i][j] = looking[j]; j++)
		{
			if (j == 3)
				break;
		}
		if (j == 3)
			break;
	}
	return(environ[i]);
}

/**
 * *_strcat - concatenate two strings
 * @dest: destin
 * @src: source
 * @n: number
 * Return: dest.
 */
char *_strcat(char *dest, char *src)
{
	int i = 0, j = 0;

	while (dest[i] != '\0')
	{
		i++;
	}
	dest[i] = '/';
	i++;
	while (src[j] != '\0')
	{
		dest[i] = src[j];
		j++;
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

/*
 * execute_arguments - function to execute all arguments founded
 * @b: string
 * Return: Always 0.

int execute_arguments(int argc, char **argv, char **env)
{

}
*/
