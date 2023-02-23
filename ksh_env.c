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
*@var: var_t struct.
*Return: None.
*/
int ksh_env(char **argv, var_t *var)
{
	if (!argv[1])
	{
		print_environ(var->env);
	}
	else
	{
		char **commands = parse_command(argv[1]);

		execute_single_command(commands, var);
		free(commands);
	}

	return (0);
}
