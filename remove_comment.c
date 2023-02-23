#include "main.h"

/**
 * remove_comment - removes comment from the command to be executed.
 *
 * @cmd: command to be executed.
 *
 * Return: command without the comment or NULL if the whole command is a
 * comment.
 */
char *remove_comment(char *cmd)
{
	size_t i = 0;

	while (cmd[i])
	{
		if (cmd[i] == '#')
		{
			if (i == 0)
			{
				free(cmd);
				return (NULL);
			}
			else if (isspace(cmd[i - 1]) || cmd[i - 1] == ';')
			{
				break;
			}
		}
		i++;
	}

	if ((i + 1) != strlen(cmd))
	{
		cmd = realloc(cmd, i + 1);
		cmd[i] = '\0';
	}

	return (cmd);
}
