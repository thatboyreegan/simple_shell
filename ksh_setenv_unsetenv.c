#include "main.h"
/**
*ksh_setenv - sets an environment variable.
*@argv: array of arguments.
*@var: var_t struct.
*Return: 0 on success, 127 on error..
*/
int ksh_setenv(char **argv, var_t *var)
{
	if (argv[1] && argv[2])
	{
		if (setenv(argv[1], argv[2], 1) == -1)
			perror("setenv");
	}
	else
	{
		return (error_setenv(argv, var));
	}
	return (0);
}

/**
*ksh_unsetenv - unsets environment variable.
*@argv: array of arguments.
*@var: var_t struct.
*Return: 0 on success, 127 on error.
*/
int ksh_unsetenv(char **argv, var_t *var)
{
	if (argv[1])
	{
		if (unsetenv(argv[1]) == -1)
			perror("unsetenv");
	}
	else
	{
		return (error_setenv(argv, var));
	}
	return (0);
}
