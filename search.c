#include "main.h"

/**
 * search_path - search the absolute filepath for the program entered.
 *
 * @filename: Name of the program to search for.
 *
 * Return: Full path to the program, or NULL if it's not found.
 */
char *search_path(char *filename)
{
	char *path, *filepath, **paths;
	int pos = 0;

	path = _getenv("PATH");
	paths = parse_path(path);

	while (paths[pos])
	{
		struct stat st;

		filepath = get_abs_path(paths[pos], filename);

		if (!filepath)
			exit_search_safe(paths, filepath);

		if (stat(filepath, &st) == 0)
		{
			free(paths[0]);
			free(paths);
			return (filepath);
		}
		pos++;
		free(filepath);
	}
	free(paths[0]);
	free(paths);
	return (NULL);
}

/**
 * get_abs_path - appends the program name to the given directory
 * gotten from the path.
 *
 * @filedir: PATH diretory.
 * @filename: Name of the program.
 *
 * Return: generated absolute path to the program.
 */
char *get_abs_path(char *filedir, char *filename)
{
	char *filepath;

	filepath = strdup(filedir);
	if (!filepath)
		return (NULL);

	filepath = realloc(filepath, (strlen(filepath) + strlen(filename) + 2));
	if (!filepath)
	{
		free(filepath);
		return (NULL);
	}

	strcat(filepath, "/");
	strcat(filepath, filename);

	return (filepath);
}

/**
 * parse_path - creates a NULL terminated array of the directories found in
 * the PATH environment variable.
 *
 * @path: PATH environment variable value.
 *
 * Return: NULL terminated array of the PATH directories.
 */
char **parse_path(char *path)
{
	size_t bufsize = BUF_SIZE, pos = 0;
	char *token, *localpath;
	char  **tokens = malloc(sizeof(char *) * bufsize);

	if (!tokens)
	{
		perror("parse_path: Memory allocation failed");
		exit(EXIT_FAILURE);
	}
	localpath = strdup(path);
	if (!localpath)
	{
		perror("parse_path: Memory allocation failed");
		free(tokens);
		exit(EXIT_FAILURE);
	}

	token = _strtok(localpath, ":");
	while (token)
	{
		tokens[pos++] = token;
		token = _strtok(NULL, ":");

		if (pos >= bufsize)
		{
			bufsize += BUF_SIZE;
			tokens = realloc(tokens, sizeof(char *) * bufsize);
			if (!tokens)
			{
				perror("Memory allocation failed");
				free(localpath);
				free(tokens);
				exit(EXIT_FAILURE);
			}
		}
	}
	tokens[pos] = NULL;
	return (tokens);
}

/**
 * exit_search_safe - exit search safely.
 *
 * @paths: NULL terminated array of PATH directories.
 * @filepath: absolute path to the program.
 *
 * Return: void.
 */
void exit_search_safe(char **paths, char *filepath)
{
	free(paths[0]);
	free(paths);

	if (filepath)
		free(filepath);

	if (errno)
	{
		perror("search_path: memory allocation failure\n");
		exit(EXIT_FAILURE);
	}
}
