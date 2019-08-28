#include "shell_header.h"

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
	return(environ[i]);
}

/**
 * *_strcat - concatenate two strings
 * @dest: destin
 * @src: source
 * @n: number
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
/*
 *  execute_arguments - function to execute all arguments founded
 * @b: string
 * Return: Always 0.
 */
int hilos_programa(char **args, int num)
{
  //Declaramos el PID y su estado
  pid_t pid;
  int estado;
  //iniciamos el fork
  pid = fork();
  if (pid < 0) {
    printf("error xd\n");
  } else if (pid == 0) {
    if (execvp(args[0], args) == -1) printf("error xd comando no existe ESPERANZA METASE EL DEDO\n");
    exit(EXIT_FAILURE);
  } else {
    //proceso ejecutando
    do {
      waitpid(pid, &estado, WUNTRACED);
    } while (!WIFEXITED(estado) && !WIFSIGNALED(estado));
  }
  return 1;
}
