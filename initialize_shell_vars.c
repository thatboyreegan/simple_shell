#include "main.h"

/**
 * initialize_shell_var - initialize the var_t struct.
 *
 * @argv: argument vector.
 * @envp: environment variable.
 *
 * Return: Returns initialized var_t struct.
 */
var_t *initialize_shell_var(char **argv, char **envp)
{
	var_t *new_shell = malloc(sizeof(var_t));

	if (!new_shell)
		return (NULL);

	strcpy(new_shell->shell_name, argv[0]);
	new_shell->cmd_num = 1;
	new_shell->env = envp;

	return (new_shell);
}
