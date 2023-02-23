#include "main.h"

int execute_NONE(char **argv, var_t *var);
int execute_SEMICOLON(char **argv, var_t *var);
int execute_AND(char **argv, var_t *var);
int execute_OR(char **argv, var_t *var);

/**
 * execute_commands - executes commands given depending on the
 * next separator.
 *
 * @command: the command to execute.
 * @var: var_t struct.
 *
 * Return: 0 if all commands are executed successfully, or -1
 * if an error occurs.
 */
int execute_commands(char *command, var_t *var)
{
	char **commands;

	switch (var->sep)
	{
	case NONE:
		commands = parse_command(command);
		if (execute_NONE(commands, var) == -1)
			return (-1);
		free(commands);
		break;
	case SEMICOLON:
		commands = split_commands(command, ";\n\0");
		if (execute_SEMICOLON(commands, var) == -1)
			return (-1);
		free(commands);
		break;
	case AND:
		commands = split_commands(command, "&\n\0");
		if (execute_AND(commands, var) == -1)
			return (-1);
		free(commands);
		break;
	case OR:
		commands = split_commands(command, "|\n\0");
		if (execute_OR(commands, var) == -1)
			return (-1);
		free(commands);
		break;
	}
	return (0);
}

/**
 * execute_NONE - execute command when the separator is NONE.
 *
 * @commands: NULL terminated array conatining program name and arguments.
 * @var: var_t struct.
 *
 * Return: 0 on success, -1 on failure.
 */
int execute_NONE(char **commands, var_t *var)
{
	if (execute_builtin(commands, var) == -1)
	{
		if (execute_single_command(commands, var) == -1)
		{
			free(commands);
			return (-1);
		}
	}
	return (0);
}

/**
 * execute_SEMICOLON - executed when separator is SEMICOLON.
 *
 * @commands: NULL terminated array conatining program name and arguments.
 * @var: var_t struct.
 *
 * Return: 0 on success, -1 on failure.
 */
int execute_SEMICOLON(char **commands, var_t *var)
{
	if (parse_and_exec(commands, var) == -1)
	{
		free(commands);
		return (-1);
	}
	return (0);
}

/**
 * execute_AND - executed when separator is AND.
 *
 * @commands: NULL terminated array conatining program name and arguments.
 * @var: var_t struct.
 *
 * Return: 0 on success, -1 on failure.
 */
int execute_AND(char **commands, var_t *var)
{
	if (parse_and_exec(commands, var) == -1)
	{
		free(commands);
		return (-1);
	}
	return (0);
}

/**
 * execute_OR - executed when separator is OR.
 *
 * @commands: NULL terminated array conatining program name and arguments.
 * @var: var_t struct.
 *
 * Return: 0 on success, -1 on failure.
 */
int execute_OR(char **commands, var_t *var)
{
	if (parse_and_exec(commands, var) == -1)
	{
		free(commands);
		return (-1);
	}
	return (0);
}
