#include "shell_header.h"

/**
 * function_cd - verify if argument is a existing directory,
 * if not have arguments ask for one
 * @args: argument
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
	return 1;
}

/**
 * function_exit - command exit
 * @args: arguments
 */
int function_exit(char **args)
{
	return 0;
}

/**
 * iniciar un disparador y esperar que termine
 */
int hilos_programa(char **args)
{
  //Declaramos el PID y su estado
  pid_t pid;
  int estado;
  //iniciamos el fork
  pid = fork();
  if (pid < 0) {
    printf("error pid < 0\n");
  }
  else if (pid == 0) {
	  if (execvp(args[0], args) == -1) printf("error xd comando no existe ESPERANZA METASE EL DEDO\n");
	  exit(EXIT_FAILURE);}
  {
    //proceso ejecutando
    do {
      waitpid(pid, &estado, WUNTRACED);
    } while (!WIFEXITED(estado) && !WIFSIGNALED(estado));
  }
  return 1;
}
