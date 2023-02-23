#include "main.h"

/**
 * get_next_separator - gets next separator in the command.
 *
 * @command: the command as entered by user.
 *
 * Return: Next separator found.
 */
Separator get_next_separator(const char *command)
{
	while (*command++)
	{
		if (*command == ';')
			return (SEMICOLON);
		else if (*command == '&')
			return (AND);
		else if (*command == '|')
			return (OR);
	}
	return (NONE);
}
