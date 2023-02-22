#include "main.h"
/**
*ksh_exit - terminates a process.
*@argv: the status.
*Return: None.
*/
void ksh_exit(char **argv)
{
	int status;

	if (!argv[1])
	{
		free(argv[0]);
		free(argv);
		exit(EXIT_SUCCESS);
	}
	else if (argv[1])
	{
		status = atoi(argv[1]);
		free(argv[0]);
		free(argv);
		exit(status);
	}
	else if (argv[1] && argv[2])
	{
		errno = E2BIG;
		fprintf(stderr, "%s: %s: ", "ksh", argv[0]);
		perror("");
	}
}
