#include "main.h"

/**
 * execute_single_command - executes a single command by calling
 * a child process.
 *
 * @argv: Null terminated array containing program name and arguments.
 * @envp: Null terminated array containing environment variables.
 *
 * Return: 0 on success, -1 on failure.
 */
int execute_single_command(char **argv, char **envp)
{
	char *prog_name;

	prog_name = check_prog_name(argv[0]);

	if (prog_name)
	{
		return (run_child(prog_name, argv, envp));
	}
	else
	{
		perror("ksh");
		return (-1);
	}

	return (0);
}

/**
 * run_child - forks and executes a child process.
 *
 * @prog_name: name of the program to execute.
 * @argv: Null terminated array containing program name and arguments.
 * @envp: Null terminated array containing environment variables.
 *
 * Return: 0 on success, -1 on failure.
 */
int run_child(char *prog_name, char **argv, char **envp)
{
	pid_t child_pid;
	int status;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("ksh");
		return (-1);
	}
	if (child_pid == 0)
	{
		if (execve(prog_name, argv, envp) == -1)
		{
			perror("ksh");
			free(prog_name);
			free(argv);
			return (-1);
		}
	}
	else
	{
		do {
			waitpid(-1, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
		free(prog_name);
	}
	return (0);
}
