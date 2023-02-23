#include "main.h"

/**
 * parse_and_exec - executes commands as given by user.
 *
 * @commands: NULL terminated aarray of parsed commands.
 * @var: var_t struct.
 *
 * Return: 0 on success, -1 on failure.
 */
int parse_and_exec(char **commands, var_t *var)
{
	int i = 0;
	char *cmd = NULL;

	while (commands[i])
	{
		if (i == 0)
		{
			if (_exec(commands[i], var) == -1)
				return (-1);
		}
		else
		{
			cmd = commands[i];
			var->sep = get_next_separator(cmd);
			if (var->sep != NONE)
			{
				if (execute_commands(cmd, var) == -1)
					return (-1);
			}
			else
			{
				if (_exec(cmd, var) == -1)
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
 * @var: var_t struct.
 *
 * Return: 0 on success, -1 on failure.
 */
int _exec(char *command, var_t *var)
{
	char **commands = parse_command(command);

	switch (var->sep)
	{
	case NONE:
		if (execute_builtin(commands, var) == -1)
			execute_single_command(commands, var);
		break;
	case SEMICOLON:
		if (execute_builtin(commands, var) == -1)
			execute_single_command(commands, var);
		break;
	case AND:
		if (execute_builtin(commands, var) == -1)
		{
			if (execute_single_command(commands, var) == -1)
			{
				free(commands);
				return (-1);
			}
		}
		break;
	case OR:
		if (execute_builtin(commands, var) == -1)
		{
			if (execute_single_command(commands, var) != -1)
			{
				free(commands);
				return (-1);
			}
		}
		break;
	}
	free(commands);
	return (0);
}
