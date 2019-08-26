#include "shell_header.h"

/* call functions */
char *array_str[] = {
  "cd",
  "echo",
  "pause",
  "exit"
};

// ----- array de funciones (DISPARADORES) -----------
int (*array_funciones[]) (char **) = {
  &function_cd,
  &function_exit
};

/**
 * main - main function
 * @argc: amount of arguments
 * @argv: arguments
 */
int main(int argc, char **argv)
{
    char *line;
    char **args;
    int state;

    loop_shell();
/* no necesary */
    do
    {
	    write(1, "$ ", 2);0B
	    if(argv[1] != NULL)
	    {
		    line = argv[1];
	    }else
		    line = lectura();
	    args = split_linea(line);
	    state = comando(args);
	    free(line);
	    free(args);
    } while (state);
    return EXIT_SUCCESS;
/* no necesary */

    return (0);
}
