#include "main.h"
/**
*get_builtin_cmd - gets a built in command.
*@argv: array of arguments.
*Return: builtin command or NULL if not found.
*/
void (*get_builtin_cmd(char **argv))(char **)
{
	int i;

	builtin_t Builtin[] = {
		{"cd", ksh_cd},
		{"exit", ksh_exit},
		{"setenv", ksh_setenv},
		{"unsetenv", ksh_unsetenv},
		{"env", ksh_env},
		{"0", NULL}
	};

	i = 0;
	while (Builtin[i].func != NULL)
	{
		if (strcmp(Builtin[i].cmd, argv[0]) == 0)
			return (Builtin[i].func);
		i++;
	}
	return (NULL);
}
/**
*execute_builtin - executes builtin commands.
*@argv: builtin command.
*Return: 0 if successful or -1 if an error is encounterd
*/
int execute_builtin(char **argv)
{
	void (*func)(char **);

	func = get_builtin_cmd(argv);
	if (func)
	{
		func(argv);
		return (0);
	}
	else
	{
		return (-1);
	}
}
