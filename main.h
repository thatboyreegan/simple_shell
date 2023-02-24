#ifndef _main_h
#define _main_h


#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <ctype.h>
#include <signal.h>

#define BUF_SIZE 30

extern char **environ;

/**
*enum separator - contains separators.
*@NONE: no separator.
*@SEMICOLON: semicolon separator.
*@AND: && separator.
*@OR: || separator.
*/
typedef enum separator
{
	NONE,
	SEMICOLON,
	AND,
	OR
} Separator;

/**
 * struct var_s - struct containing shell variables.
 *
 * @shell_name: name of the executable shell.
 * @cmd_num: number of the command being run.
 * @cmd: command to be ran.
 * @env: environment.
 * @sep: separator between commands.
 */
typedef struct var_s
{
	char shell_name[20];
	int cmd_num;
	char *cmd;
	char **env;
	Separator sep;
} var_t;

/**
*struct builtin_s - contains the builtins.
*@cmd: command.
*@func: void function pointed to another function.
*@void (*func)(char **): the corresping function for the command.
*/
typedef struct builtin_s
{
	char cmd[10];
	int (*func)(char **, var_t *);
} builtin_t;

void shell_loop(var_t *var);
int execute_file_cmd(char *filename, var_t *var);
void check_and_execute_cmd(char *cmd, var_t *var, size_t len);
char *command_sub(char *cmd);
void handle_signal_2(int);
char *remove_comment(char *cmd);
char *check_prog_name(char *filename);
int execute_single_command(char **argv, var_t *var);
int run_child(char *prog_name, char **argv, char **envp);
int _exec(char *command, var_t *var);
int parse_and_exec(char **commands, var_t *var);
char **split_commands(char *command, const char *delim);
int execute_commands(char *command, var_t *var);
var_t *initialize_shell_var(char **argv, char **envp);

char *get_command(var_t *var);
char **parse_command(char *command);
int check_command(const char *command);
char *search_path(char *filename);
char *get_abs_path(char *filedir, char *filename);
char **parse_path(char *path);
void exit_search_safe(char **paths, char *filepath);

char *_getenv(const char *name);
char *_strtok(char *str, const char *delim);

int (*get_builtin_cmd(char **argv))(char **, var_t *);
int execute_builtin(char **argv, var_t *var);
int ksh_cd(char **argv, var_t *var);
int ksh_exit(char **argv, var_t *var);
int ksh_setenv(char **argv, var_t *var);
int ksh_unsetenv(char **argv, var_t *var);
int ksh_env(char **argv, var_t *var);

Separator get_next_separator(const char *command);

int error_not_found(char *cmd, var_t *var);
int error_cd(char **argv, var_t *var, int i);
int error_exit(char **argv, var_t *var);
int error_setenv(char **argv, var_t *var);
int error_opening_file(char *filename, var_t *var);

char *convert_to_str(int i);
int convert_to_int(char *str);
void rev_str(char *str, int i);

#endif
