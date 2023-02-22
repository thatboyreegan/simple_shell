#include "main.h"

/**
 * check_prog_name - checks whether program given is valid.
 *
 * @filename: Name of the program to check or path to the program.
 *
 * Return: Path to the progrm or NULL if not found.
 */
char *check_prog_name(char *filename)
{
	struct stat st;
	char *filepath;

	if (!filename)
		return (NULL);

	if (filename[0] == '.' && filename[1] == '/')
	{
		if (stat(filename + 2, &st) == 0)
			return (strdup(filename));
		else
			return (NULL);
	}
	else if (filename[0] == '/')
	{
		if (stat(filename, &st) == 0 && S_ISREG(st.st_mode))
		{
			return (strdup(filename));
		}
		else
		{
			perror("prog_name");
			return (NULL);
		}
	}

	filepath = search_path(filename);
	if (filepath)
	{
		return (filepath);
	}
	else
	{
		free(filepath);
		return (NULL);
	}
}
