#include "main.h"

char *get_command_line(int fd, char *c);

/**
 * execute_file_cmd - execute commands in a file. The file has
 * a single command on each line. Every command should be on its
 * own line and file must have blank line at end.
 *
 * @filename: name of the file.
 * @var: var_t structure.
 *
 * Return: 0 on success, -1 if file cannot be opened, 1 if file's content
 * cannot be read or if it's empty.
 */
int execute_file_cmd(char *filename, var_t *var)
{
	int fd, r_bytes;
	size_t len;
	char c, *cmd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (-1);

	r_bytes = read(fd, &c, sizeof(char));
	if (r_bytes == 0 || r_bytes == -1)
		return (1);

	while (c != EOF && r_bytes != -1 && r_bytes != 0)
	{
		while (c == '\n')
		{
			var->cmd_num++;
			r_bytes = read(fd, &c, sizeof(char));
			if (c == EOF || r_bytes == -1)
			{
				close(fd);
				return (1);
			}
		}
		cmd = get_command_line(fd, &c);
		if (!cmd)
		{
			perror("");
			close(fd);
			return (1);
		}
		len = strlen(cmd);
		check_and_execute_cmd(cmd, var, len);
		r_bytes = read(fd, &c, sizeof(char));
		if (r_bytes < 0)
		{
			return (0);
		}
	}
	close(fd);
	return (0);
}

/**
 * get_command_line - read command from file.
 *
 * @fd: file descriptor of the file to read from.
 * @c: pointer to the last read character.
 *
 * Return: string containing the command to execute.
 */
char *get_command_line(int fd, char *c)
{
	char *cmd;
	int r_bytes;
	size_t bufsize = BUF_SIZE, pos;

	cmd = malloc(sizeof(char) * bufsize);
	if (!cmd)
		return (NULL);

	for (pos = 0; *c != '\n' && *c != EOF; pos++)
	{
		printf("TWO\n");
		printf("c2: %d\n", *c);
		if (pos >= bufsize)
		{
			bufsize += BUF_SIZE;
			cmd = realloc(cmd, bufsize);
			if (!cmd)
			{
				free(cmd);
				return (NULL);
			}
		}

		*(cmd + pos) = *c;
		r_bytes = read(fd, c, sizeof(char));
		if (r_bytes == -1)
		{
			free(cmd);
			return (NULL);
		}
	}
	*(cmd + pos) = '\0';

	return (cmd);
}
