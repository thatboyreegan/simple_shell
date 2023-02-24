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
	size_t len;

	while (1)
	{
		write(STDIN_FILENO, "$ ", 3);
		cmd = get_command(var);

		len = strlen(cmd) - 1;
		check_and_execute_cmd(cmd, var, len);
	}
}

/**
 * check_and_execute_cmd - verify command and execute it.
 *
 * @cmd: command to check and run.
 * @var: var_t structure.
 * @len: length of the command.
 *
 * Return: void.
 */
void check_and_execute_cmd(char *cmd, var_t *var, size_t len)
{
	if (strcmp(cmd, "\n") == 0 || strspn(cmd, " ") == len)
	{
		free(cmd);
		var->cmd_num++;
		return;
	}

	cmd = remove_comment(cmd);
	if (cmd)
	{
		if (check_command(cmd) != -1)
		{
			cmd = command_sub(cmd);
			if (!cmd)
			{
				var->cmd_num++;
				free(cmd);
				return;
			}
			var->sep = get_next_separator(cmd);
			var->cmd = cmd;
			execute_commands(var->cmd, var);
		}
		free(cmd);
	}
	var->cmd_num++;
}
