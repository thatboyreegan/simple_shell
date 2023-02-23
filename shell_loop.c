#include "main.h"

/**
 * shell_loop - contains the shell loop.
 *
 * @var: var_t struct.
 *
 * Return: void.
 */
void shell_loop(var_t *var)
{
	char *cmd;

	while (1)
	{
		write(STDIN_FILENO, "$ ", 3);
		cmd = get_command(var);
		if (strcmp(cmd, "\n") == 0 || strspn(cmd, " ") == (strlen(cmd) - 1))
		{
			free(cmd);
			var->cmd_num++;
			continue;
		}

		cmd = remove_comment(cmd);
		if (cmd)
		{
			if (check_command(cmd) != -1)
			{
				var->sep = get_next_separator(cmd);
				var->cmd = cmd;
				execute_commands(var->cmd, var);
			}
			free(cmd);
		}
		var->cmd_num++;
	}
}
