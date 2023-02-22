#include "main.h"

int execute_NONE(char **argv, char **envp, Separator s);
int execute_SEMICOLON(char **argv, char **envp, Separator s);
int execute_AND(char **argv, char **envp, Separator s);
int execute_OR(char **argv, char **envp, Separator s);

/**
 * execute_commands - executes commands given depending on the
 * next separator.
 *
 * @command: the command to execute.
 * @envp: Null terminated array of evironment variables.
 * @s: next separator.
 *
 * Return: 0 if all commands are executed successfully, or -1
 * if an error occurs.
 */
int execute_commands(char *command, char **envp, Separator s)
{
	char **commands;

	switch (s)
	{
	case NONE:
		commands = parse_command(command);
		if (execute_NONE(commands, envp, s) == -1)
			return (-1);
		free(commands);
		break;
	case SEMICOLON:
		commands = split_commands(command, ";\n\0");
		if (execute_SEMICOLON(commands, envp, s) == -1)
			return (-1);
		free(commands);
		break;
	case AND:
		commands = split_commands(command, "&\n\0");
		if (execute_AND(commands, envp, s) == -1)
			return (-1);
		free(commands);
		break;
	case OR:
		commands = split_commands(command, "|\n\0");
		if (execute_OR(commands, envp, s) == -1)
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
 * @envp: NULL terminated array of environment variables.
 * @s: Separator.
 *
 * Return: 0 on success, -1 on failure.
 */
int execute_NONE(char **commands, char **envp, Separator s)
{
	if (execute_builtin(commands) == -1)
	{
		if (parse_and_exec(commands, envp, s) == -1)
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
 * @envp: NULL terminated array of environment variables.
 * @s: Separator.
 *
 * Return: 0 on success, -1 on failure.
 */
int execute_SEMICOLON(char **commands, char **envp, Separator s)
{
	if (parse_and_exec(commands, envp, s) == -1)
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
 * @envp: NULL terminated array of environment variables.
 * @s: Separator.
 *
 * Return: 0 on success, -1 on failure.
 */
int execute_AND(char **commands, char **envp, Separator s)
{
	if (parse_and_exec(commands, envp, s) == -1)
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
 * @envp: NULL terminated array of environment variables.
 * @s: Separator.
 *
 * Return: 0 on success, -1 on failure.
 */
int execute_OR(char **commands, char **envp, Separator s)
{
	if (parse_and_exec(commands, envp, s) == -1)
	{
		free(commands);
		return (-1);
	}
	return (0);
}
