#include "main.h"

/**
 * get_command - read command entered by user
 *
 * Return: string containing the command.
 */
char *get_command(void)
{
	char *line = NULL;
	size_t n = 0;

	while (!line)
	{
		printf("%s", "$ ");
		if (getline(&line, &n, stdin) == -1)
		{
			free(line);
			if (feof(stdin))
			{
				exit(EXIT_SUCCESS);
			}
			else
			{
				perror("Error");
				exit(EXIT_FAILURE);
			}
		}

		if (strcmp(line, "\n") == 0 || strspn(line, " ") == (strlen(line) - 1))
		{
			free(line);
			line = NULL;
			n = 0;
		}
	}
	return (line);
}
