#include "main.h"
/**
*ksh_setenv - sets an environment variable.
*@argv: array of arguments.
*@var: var_t struct.
*Return: None.
*/
void ksh_setenv(char **argv, var_t *var)
{
	if (argv[1] && argv[2] && !argv[3])
	{
		if (setenv(argv[1], argv[2], 1) == -1)
			perror("setenv");
	}
	else
	{
		errno = E2BIG;
		fprintf(stderr, "%s: %s: ", var->shell_name, argv[0]);
		perror("");
		return;
	}
}

/**
*ksh_unsetenv - unsets environment variable.
*@argv: array of arguments.
*@var: var_t struct.
*Return: None.
*/
void ksh_unsetenv(char **argv, var_t *var)
{
	if (argv[1 && !argv[2]])
	{
		if (unsetenv(argv[1]) == -1)
			perror("unsetenv");
	}
	else
	{
		errno = E2BIG;
		fprintf(stderr, "%s: %s: ", var->shell_name, argv[0]);
		perror("");
		return;
	}
}
