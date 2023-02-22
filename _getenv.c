#include "main.h"
/**
*_getenv - gets envirnment variable.
*@name: name of variable to get.
*Return: the nevironment variable.
*/
char *_getenv(const char *name)
{
	size_t pos = 0;
	size_t len = strlen(name);

	if (!environ || !name || strcmp(name, "=") == 0)
		return (NULL);

	while (strncmp(name, environ[pos], len) != 0)
	{
		if (environ[++pos] == NULL)
			return (NULL);
	}

	if (environ[pos])
		return (environ[pos] + len + 1);
}
