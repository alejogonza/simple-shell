#include "shell_header.h"

/**
 * _strcmp - comparison between strings
 * @str1: string 1
 * @str2: string 2
 * Return: rest type int.
 */
int _strcmp(char *str1, char *str2)
{
	int rest = 0;

	while (*str1 == *str2 && *str1 != 0 && *str2 != 0)
	{
		str1++;
		str2++;
	}
	rest = *str1 - *str2;
	return (rest);
}


/**
 * getpath - function to have the PATH line from env
 * @looking: value to compare
 * Return: rest type int.
 */
char *getpath(char *looking)
{
	int i = 0, j = 0, count = 0, breaker = 0;

	for (; environ[i] != NULL; i++)
	{
		for (j = 0, count = 0; environ[i][j] == looking[j]; j++, count++)
		{
			if (count == 4)
			{
				breaker = 1;
				break;
			}
		}
		if (breaker)
			break;
	}
	return (environ[i]);
}

/**
 * *_strcat - concatenate two strings
 * @s1: string 1
 * @s2: string 2
 * Return: dest.
 */
char *_strcat(char *s1, char *s2)
{
	char *p = NULL;
	int x = 0, y = 0, z, c;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";
	while (s1[x] != '\0')
		x++;
	while (s2[y] != '\0')
		y++;
	p = malloc(sizeof(char) * ((x + y) + 1));
	if (p != 0)
	{
		for (z = 0; z < x; z++)
			p[z] = s1[z];
		for (z = z, c = 0; z < (x + y); z++, c++)
			p[z] = s2[c];
		p[z] = '\0';
		return (p);
	}
	else
		return (p);
}
/**
 *  execute_arguments - function to execute all arguments founded
 * Return: Always 0.
 */
int execute_arguments()
{
	pid_t child_pid;
	int status;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Error:");
		return (1);
	}
	if (child_pid == 0)
	{
		printf("Wait for me, wait for me\n");
		sleep(3);
	}
	else
	{
		wait(&status);
		printf("Oh, it's all better now\n");
	}
	return (0);
}
*/
