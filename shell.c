#include "shell_header"

/**
 * main - main function
 * @b: string
 * Return: Always 0.
 */

int main (int argc, char **argv, char **env)
{
	/* call loop - file looper.c */
	loop_shell();
	return (0);
}
