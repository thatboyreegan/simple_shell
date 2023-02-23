#include "main.h"
/**
*ksh_exit - terminates a process.
*@argv: the status.
*@var: var_t struct.
*Return: None.
*/
void ksh_exit(char **argv, var_t *var)
{
	int status;

	if (!argv[1])
	{
		free(argv[0]);
		free(var);
		free(argv);
		exit(EXIT_SUCCESS);
	}
	else if (argv[1] && argv[2])
	{
		errno = E2BIG;
		fprintf(stderr, "%s: %s: ", "ksh", argv[0]);
		perror("");
	}
	else if (argv[1])
	{
		free(var);
		status = atoi(argv[1]);
		free(argv[0]);
		free(argv);
		exit(status);
	}
}
