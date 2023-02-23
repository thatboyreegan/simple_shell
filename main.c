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
	var_t *shell_var = initialize_shell_var(argv, envp);

	(void) argc;

	if (!shell_var)
		return (1);

	signal(SIGINT, handle_signal_2);

	shell_loop(shell_var);

	free(shell_var);
	return (0);
}
