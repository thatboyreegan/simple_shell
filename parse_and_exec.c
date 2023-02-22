#include "main.h"

/**
 * parse_and_exec - executes commands as given by user.
 *
 * @commands: NULL terminated aarray of parsed commands.
 * @envp: environment.
 * @n: separator.
 *
 * Return: 0 on success, -1 on failure.
 */
int parse_and_exec(char **commands, char **envp, Separator n)
{
	int i = 0;
	char *cmd = NULL;

	while (commands[i])
	{
		if (i == 0)
		{
			if (_exec(commands[i], envp, n) == -1)
				return (-1);
		}
		else
		{
			cmd = commands[i];
			n = get_next_separator(cmd);
			if (n != NONE)
			{
				if (execute_commands(cmd, envp, n) == -1)
					return (-1);
			}
			else
			{
				if (_exec(cmd, envp, n) == -1)
					return (-1);
			}
		}
		i++;
	}
	return (0);
}


/**
 * _exec - executes a single command depending on the next
 * separator.
 *
 * @command: command to execute.
 * @envp: environment.
 * @n: separator.
 *
 * Return: 0 on success, -1 on failure.
 */
int _exec(char *command, char **envp, Separator n)
{
	char **commands = parse_command(command);

	switch (n)
	{
	case NONE:
		if (execute_builtin(commands) == -1)
			execute_single_command(commands, envp);
		free(commands);
		break;
	case SEMICOLON:
		if (execute_builtin(commands) == -1)
			execute_single_command(commands, envp);
		free(commands);
		break;
	case AND:
		if (execute_builtin(commands) == -1)
		{
			if (execute_single_command(commands, envp) == -1)
			{
				free(commands);
				return (-1);
			}
		}
		free(commands);
		break;
	case OR:
		if (execute_builtin(commands) == -1)
		{
			if (execute_single_command(commands, envp) != -1)
			{
				free(commands);
				return (-1);
			}
		}
		free(commands);
		break;
	}
	return (0);
}
