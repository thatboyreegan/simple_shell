#include "main.h"

int check_substitution(char *command);
int get_ppid(char *cmd, size_t *pos);
char *_realloc(char *new_cmd, size_t *bufsize);
char *create_new_cmd(char *cmd);

/**
 * command_sub - makes command substitution for $$.
 *
 * @cmd: command string.
 *
 * Return: new command with substitution done or same command
 * if no substitution is to be done, or NULL in case of an error.
 */
char *command_sub(char *cmd)
{
	char *new_cmd;

	if (check_substitution(cmd) == 1)
	{
		new_cmd = create_new_cmd(cmd);
		if (!new_cmd)
			return (NULL);
		return (new_cmd);
	}
	else
	{
		return (cmd);
	}
}

/**
 * create_new_cmd - creates new command by doing command substitution
 * for $$.
 *
 * @cmd: command string.
 *
 * Return: New command with substitution done, or NULL in case of an error.
 */
char *create_new_cmd(char *cmd)
{
	size_t pos, pos1, bufsize = BUF_SIZE;
	char *new_cmd;

	new_cmd = malloc(sizeof(char) * bufsize);
	if (!new_cmd)
	{
		perror("new_cmd");
		return (NULL);
	}
	pos = pos1 = 0;
	while (cmd[pos] != '\n' && cmd[pos] != '\0')
	{
		if (cmd[pos] == '$' && cmd[pos + 1] == '$')
		{
			if (get_ppid(new_cmd, &pos1) == 1)
			{
				free(new_cmd);
				return (NULL);
			}
			pos++;
		}
		else
		{
			*(new_cmd + pos1) = cmd[pos];
			pos1++;
		}
		pos++;
		if (pos1 >= bufsize)
		{
			new_cmd = _realloc(new_cmd, &bufsize);
			if (!new_cmd)
				return (NULL);
		}
	}
	*(new_cmd + pos1) = '\0';
	free(cmd);
	return (new_cmd);
}

/**
 * check_substitution - chaeck whether the command has any
 * commands to be substituted.
 *
 * @command: command to be check.
 *
 * Return: 1 if a substitution is to be done, 0 if there's none.
 */
int check_substitution(char *command)
{
	int i = 0;

	while (command[i])
	{
		if (command[i] == '$')
			return (1);
		i++;
	}
	return (0);
}

/**
 * get_ppid - get the parent id and append it to the command.
 *
 * @cmd: command to append the parent id.
 * @pos: index to start appending.
 *
 * Return: 0 on success, 1 on failure.
 */
int get_ppid(char *cmd, size_t *pos)
{
	pid_t parent_id;
	char *parent_id_str;

	parent_id = getppid();
	parent_id_str = convert_to_str(parent_id);

	if (!parent_id_str)
	{
		perror("ppid");
		return (1);
	}
	strcpy(cmd + *pos, parent_id_str);

	*pos += strlen(parent_id_str);
	free(parent_id_str);

	return (0);
}

/**
 * _realloc - reallocates new command string in case it doesn't
 * fit the previous command.
 *
 * @new_cmd: command to reallocate.
 * @bufsize: size of the command being reallocated.
 *
 * Return: New command string with reallocated memory.
 */
char *_realloc(char *new_cmd, size_t *bufsize)
{
	*bufsize += BUF_SIZE;

	new_cmd = realloc(new_cmd, *bufsize);
	if (!new_cmd)
	{
		free(new_cmd);
		perror("new_cmd");
		return (NULL);
	}
	return (new_cmd);
}
