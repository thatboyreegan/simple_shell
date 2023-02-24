#include "main.h"

/**
 * main - entry point.
 *
 * @argc: argument count.
 * @argv: argument vector.
 *
 * Return: 0 on success, 1 on failure.
 */
int main(int argc, char **argv)
{
	var_t *shell_var = initialize_shell_var(argv, environ);

	if (!shell_var)
		return (1);

	if (argc > 1)
	{
		if (execute_file_cmd(argv[1], shell_var) == -1)
		{
			int status;

			status = error_opening_file(argv[1], shell_var);
			free(shell_var);
			return (status);
		}
	}
	else
	{
		signal(SIGINT, handle_signal_2);
		shell_loop(shell_var);
	}

	free(shell_var);
	return (0);
}
