#include "main.h"

/**
 * main - entry point.
 *
 * @argc: argument count.
 * @argv: argument vector.
 * @envp: environment.
 *
 * Return: 0 on success, 1 on failure.
 */
int main(int argc, char **argv, char **envp)
{
	char *cmd;
	var_t *shell_var = initialize_shell_var(argv, envp);

	(void) argc;

	if (!shell_var)
		return (1);

	signal(SIGINT, handle_signal_2);
	while (1)
	{
		write(STDIN_FILENO, "$ ", 3);
		cmd = get_command(shell_var);
		if (strcmp(cmd, "\n") == 0 || strspn(cmd, " ") == (strlen(cmd) - 1))
		{
			free(cmd);
			continue;
		}

		cmd = remove_comment(cmd);
		if (cmd)
		{
			if (check_command(cmd) != -1)
			{
				shell_var->sep = get_next_separator(cmd);
				shell_var->cmd = cmd;
				execute_commands(shell_var->cmd, shell_var);
			}
			free(cmd);
		}
		shell_var->cmd_num++;
	}
	free(shell_var);
	return (0);
}
