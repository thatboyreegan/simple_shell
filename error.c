#include "main.h"

char *convert_str(int i);
void rev_str(char *str, int i);

/**
 * error_not_found - print error if file is not found.
 *
 * @cmd: command passed.
 * @var: var_t struct.
 *
 * Return: void.
 */
void error_not_found(char *cmd, var_t *var)
{
	char error[200] = {0};
	char *cmd_num_str = convert_str(var->cmd_num);

	if (!cmd_num_str)
		return;

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
}

/**
 * error_cd - error to print when cd fails.
 *
 * @argv: argument vector.
 * @var: var_t struct.
 * @i: integer showing which error to output.
 *
 * Return: void.
 */
void error_cd(char **argv, var_t *var, int i)
{
	char error[200] = {0};
	char *cmd_num_str = convert_str(var->cmd_num);

	if (!cmd_num_str)
		return;

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
}

/**
 * convert_str - convert an int to a string.
 *
 * @num: integer.
 *
 * Return: string containing num.
 */
char *convert_str(int num)
{
	int digit, i = 0;
	char *str = malloc(sizeof(char) * 10);

	if (!str)
		return (NULL);

	while (num)
	{
		digit = num % 10;
		str[i++] = '0' + digit;
		num /= 10;
	}
	rev_str(str, i);
	str[i] = '\0';
	return (str);
}

/**
 * rev_str - reverse a string.
 *
 * @str: string to reverse.
 * @i: length of string.
 *
 * Return: void
 */
void rev_str(char *str, int i)
{
	int hi = i - 1;
	int lo = 0;
	char temp;

	for (; lo < hi; lo++, hi--)
	{
		temp = str[lo];
		str[lo] = str[hi];
		str[hi] = temp;
	}
}
