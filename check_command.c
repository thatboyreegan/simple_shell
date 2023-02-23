#include "main.h"

/**
 * check_command - verifies that the command does not have unexpected tokens.
 *
 * @command: command to check.
 *
 * Return: 0 if the command is correct, or -1 if there are unexpectes tokens.
 */
int check_command(const char *command)
{
	if ((strspn(command, "|") + 1) == strlen(command))
	{
		fprintf(stderr, "%s", "sh: syntax error near unexpected token `||'\n");
		return (-1);
	}
	if ((strspn(command, "&") + 1) == strlen(command))
	{
		fprintf(stderr, "%s", "sh: syntax error near unexpected token `&&'\n");
		return (-1);
	}
	if ((strspn(command, ";") + 1) == strlen(command))
	{
		fprintf(stderr, "%s", "sh: syntax error near unexpected token `;;'\n");
		return (-1);
	}

	while (*command++)
	{
		if (strspn(command, "|") > 2)
		{
			fprintf(stderr, "%s", "sh: syntax error near unexpected token `||`\n");
			return (-1);
		}
		if (strspn(command, "&") > 2)
		{
			fprintf(stderr, "%s", "sh: syntax error near unexpected token `&&`\n");
			return (-1);
		}
		if (strspn(command, ";") > 1)
		{
			fprintf(stderr, "%s", "sh: syntax error near unexpected token `;;`\n");
			return (-1);
		}
	}
	return (0);
}
