#include "main.h"

/**
*ksh_cd - the cd builtin command.
*@argv: arguments to cd.
*Return: None
*/
void ksh_cd(char **argv)
{
	char *dir, *old_dir;

	if (argv[1] && argv[2])
	{
		errno = E2BIG;
		fprintf(stderr, "%s: %s: ", "ksh", argv[0]);
		perror("");
		return;
	}
	if (!argv[1])
	{
		dir = _getenv("HOME");
	}
	else if (strcmp(argv[1], "-") == 0)
	{
		dir = _getenv("OLDPWD");
		fprintf(stdout, "%s\n", dir);
	}
	else
	{
		dir = argv[1];
	}

	if (!dir)
	{
		fputs("ksh: cd: OLDPWD not set\n", stderr);
		free(argv);
		return;
	}
	old_dir = getcwd(NULL, 0);
	if (setenv("OLDPWD", old_dir, 1) == -1)
		perror("set");

	if (chdir(dir) == -1)
		perror("cd");
	dir = getcwd(NULL, 0);
	if (setenv("PWD", dir, 1) == -1)
		perror("set");
	free(old_dir);
	free(dir);
}
