#include "main.h"

/**
 * error_exit - print error if exit status is negative number.
 *
 * @argv: argument vector.
 * @var: var_t structure.
 *
 * Return: Always 2.
 */
int error_exit(char **argv, var_t *var)
{
	char error[200] = {0};
	char *cmd_num_str = convert_to_str(var->cmd_num);

	if (!cmd_num_str)
	{
		perror("Failed to allocate cmd_num_str");
		return (2);
	}

	errno = 0;
	strcat(error, var->shell_name);
	strcat(error, ": ");
	strcat(error, cmd_num_str);
	strcat(error, ": ");
	strcat(error, argv[0]);
	strcat(error, ": ");
	strcat(error, "Illegal number ");
	strcat(error, argv[1]);
	strcat(error, "\n\0");

	write(STDERR_FILENO, error, strlen(error));

	free(cmd_num_str);

	return (2);
}

/**
 * error_not_found - print error if file is not found.
 *
 * @cmd: command passed.
 * @var: var_t struct.
 *
 * Return: Always 127.
 */
int error_not_found(char *cmd, var_t *var)
{
	char error[200] = {0};
	char *cmd_num_str = convert_to_str(var->cmd_num);

	if (!cmd_num_str)
	{
		perror("Failed to allocate cmd_num_str");
		return (127);
	}

	errno = 0;
	strcat(error, var->shell_name);
	strcat(error, ": ");
	strcat(error, cmd_num_str);
	strcat(error, ": ");
	strcat(error, cmd);
	strcat(error, ": ");
	strcat(error, "not found\n");
	strcat(error, "\0");

	write(STDERR_FILENO, error, strlen(error));

	free(cmd_num_str);

	return (127);
}

/**
 * error_cd - error to print when cd fails.
 *
 * @argv: argument vector.
 * @var: var_t struct.
 * @i: integer showing which error to output.
 *
 * Return: Always 2.
 */
int error_cd(char **argv, var_t *var, int i)
{
	char error[200] = {0};
	char *cmd_num_str = convert_to_str(var->cmd_num);

	if (!cmd_num_str)
	{
		perror("Failed to allocate cmd_num_str");
		return (2);
	}

	errno = 0;
	strcat(error, var->shell_name);
	strcat(error, ": ");
	strcat(error, cmd_num_str);
	strcat(error, ": ");
	strcat(error, argv[0]);
	strcat(error, ": ");
	if (i == 0)
	{
		strcat(error, "can't cd to ");
		strcat(error, argv[1]);
	}
	else
	{
		strcat(error, "Illegal option --");
	}
	strcat(error, "\n\0");

	write(STDERR_FILENO, error, strlen(error));

	free(cmd_num_str);

	return (2);
}

/**
 * error_setenv - print error message if there's an error setting
 * or unsetting environment.
 *
 * @argv: argument vector containing command name.
 * @var: var_t structure.
 *
 * Return: Always 2.
 */
int error_setenv(char **argv, var_t *var)
{
	char error[200] = {0};
	char *cmd_num_str = convert_to_str(var->cmd_num);

	if (!cmd_num_str)
	{
		perror("Failed to allocate cmd_num_str");
		return (2);
	}

	errno = 0;
	strcat(error, var->shell_name);
	strcat(error, ": ");
	strcat(error, cmd_num_str);
	strcat(error, ": ");
	strcat(error, argv[0]);
	strcat(error, ": ");
	strcat(error, "unabale to add/remove from environment\n");
	strcat(error, "\0");

	write(STDERR_FILENO, error, strlen(error));

	free(cmd_num_str);

	return (2);
}
