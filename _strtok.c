#include "main.h"
/**
*_strtok - tokenize a string.
*@str: string to tokenize.
*@delim: the delimiter.
*Return: tokens.
*/

char *_strtok(char *str, const char *delim)
{
	static char *buf = "";
	char *token, *s1;
	char **saveptr = &buf;

	token = str ? str : *saveptr;
	token += strspn(token, delim);
	if (*token == '\0')
	{
		*saveptr = "";
		return (NULL);
	}

	s1 = token + strcspn(token, delim);
	if (*s1 != '\0')
		*s1++ = '\0';

	*saveptr = s1;
	return (token);
}

