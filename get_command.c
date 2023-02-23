#include "main.h"

/**
 * get_command - read command entered by user
 *
 * @var: var_t struct.
 *
 * Return: string containing the command.
 */
char *get_command(var_t *var)
{
	char *line = NULL;
	size_t n = 0;

	if (getline(&line, &n, stdin) == -1)
	{
		free(line);
		if (feof(stdin))
		{
			free(var);
			exit(EXIT_SUCCESS);
		}
		else
		{
			free(var);
			perror("Error");
			exit(EXIT_FAILURE);
		}
	}
	return (line);
}
