#include "main.h"

/**
*ksh_exit - terminates a process.
*@argv: the status.
*@var: var_t struct.
*Return: exits on success, 127 on error.
*/
int ksh_exit(char **argv, var_t *var)
{
	int status;

	if (!argv[1])
	{
		free(argv[0]);
		free(var);
		free(argv);
		exit(EXIT_SUCCESS);
	}
	else if (argv[1])
	{
		status = convert_to_int(argv[1]);

		if (status < 0)
			return (error_exit(argv, var));
		free(var);
		free(argv[0]);
		free(argv);
		exit(status);
	}
	return (0);
}
