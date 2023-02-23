#include "main.h"

/**
*ksh_cd - the cd builtin command.
*@argv: arguments to cd.
*@var: var_t struct.
*Return: None
*/
void ksh_cd(char **argv, var_t *var)
{
	char *dir, *old_dir;

	if (!argv[1] || strspn(argv[1], "-") == 2)
	{
		dir = _getenv("HOME");
	}
	else if (strcmp(argv[1], "-") == 0)
	{
		dir = _getenv("OLDPWD");
		if (!dir)
		{
			fprintf(stderr, "%s: cd: OLDPWD not set\n", var->shell_name);
			return;
		}
		fprintf(stdout, "%s\n", dir);
	}
	else
	{
		if (strspn(argv[1], "-") > 2)
		{
			error_cd(argv, var, 1);
			return;
		}
		dir = argv[1];
	}

	old_dir = getcwd(NULL, 0);
	if (setenv("OLDPWD", old_dir, 1) == -1)
		perror("set");

	if (chdir(dir) == -1)
		error_cd(argv, var, 0);

	dir = getcwd(NULL, 0);
	if (setenv("PWD", dir, 1) == -1)
		perror("set");
	free(old_dir);
	free(dir);
}
