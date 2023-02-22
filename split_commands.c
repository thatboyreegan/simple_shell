#include "main.h"

/**
 * split_commands - splits a command into two strings separated
 * by the delim.
 *
 * @command: the command to split.
 * @delim: set of bytes that delimit the tokens in command
 *
 * Return: Null terminated array containing two strings or NULL on failure.
 */
char **split_commands(char *command, const char *delim)
{
	int pos = 0;
	char *token;
	char **commands = calloc(3, sizeof(char *));

	if (!commands)
		return (NULL);

	token = _strtok(command, delim);
	commands[pos++] = token;

	token = _strtok(NULL, "\n\0");

	if (delim[0] == '|' || delim[0] == '&')
	{
		commands[pos++] = token + 1;
	}
	else
	{
		commands[pos++] = token;
	}
	commands[pos] = NULL;

	return (commands);
}
