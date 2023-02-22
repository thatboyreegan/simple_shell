#include "main.h"

/**
 * main - entry point.
 *
 * Return: Always 0.
 */
int main(void)
{
	char *command;
	Separator separator;
	char **envp = environ;

	while (1)
	{
		command = get_command();
		if (check_command(command) != -1)
		{
			separator = get_next_separator(command);
			execute_commands(command, envp, separator);
		}
		free(command);
	}
	return (0);
}
