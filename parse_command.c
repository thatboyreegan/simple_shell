#include "main.h"

/**
 * parse_command - tokenizes the command entered.
 * @command: command to be parsed.
 *
 * Return: Array of tokens or NULL on failure.
 */
char **parse_command(char *command)
{
	size_t bufsize = BUF_SIZE, index;
	char **tokens, *token;

	if (!command)
		return (NULL);

	tokens = malloc(bufsize * sizeof(char *));
	if (!tokens)
	{
		perror("Failed to allocate memory");
		free(command);
		exit(EXIT_FAILURE);
	}

	token = _strtok(command, " \n");

	index = 0;
	while (token != NULL)
	{
		tokens[index++] = token;
		token = _strtok(NULL, " \n");

		if (index >= bufsize)
		{
			bufsize += BUF_SIZE;
			tokens = realloc(tokens, sizeof(char *) * bufsize);
			if (!tokens)
			{
				perror("Memory allocation failed");
				free(command);
				free(tokens);
				exit(EXIT_FAILURE);
			}
		}
	}
	tokens[index] = NULL;

	return (tokens);
}
