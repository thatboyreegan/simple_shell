#include "main.h"
/**
*print_environ - prints the environ to stdout.
*@environ: environ variable.
*Return: None.
*/
void print_environ(char **environ)
{
	int i = 0;

	while (environ[i])
	{
		write(STDOUT_FILENO, environ[i], strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
}

/**
*ksh_env - the env builtin command.
*@argv: arguments to the command.
*Return: None.
*/
void ksh_env(char **argv)
{
	if (!argv[1])
	{
		print_environ(environ);
	}
	else
	{
		errno = E2BIG;
		fprintf(stderr, "%s: %s: ", "ksh", argv[0]);
		perror("");
		return;
	}
}
