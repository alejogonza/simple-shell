#ifndef SIMPLE_SHELL
#define SIMPLE_SHELL
#define BUFSIZE 1024
#define TOK_BUFSIZE 1024
#define TOK_DELIM " \t\r\n\a"

#include <sys/wait.h>
#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

/* missing ctr c */
int funcion_clear(char **args);
int funcion_cd(char **args);
int funcion_exit(char **args);
int funcion_ls(char **args);
int funcion_pause(char **args);
int funcion_echo(char **args);
int main(int argc, char **argv);
int loop_shell(void);
char **split_line(char *buffer);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
int execute_arguments(char **args, int num_characters);
int _strcmp(char *s1, char*s2);
int function_cd(char **args);
int function_exit(char **args);
int hilos_programa(char **args);
#endif
