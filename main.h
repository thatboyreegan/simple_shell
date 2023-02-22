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

#define BUF_SIZE 30

extern char **environ;
/**
*struct builtin_s - contains the builtins.
*@cmd: command.
*@func: void function pointed to another function.
*@void (*func)(char **): the corresping function for the command.
*/
typedef struct builtin_s
{
	char cmd[10];
	void (*func)(char **);
} builtin_t;
/**
*enum separator - contains separators.
*@NONE: no separator.
*@SEMICOLON: semicolon separator.
*@AND: && separator.
*@OR: or separator.
*/
typedef enum separator
{
	NONE,
	SEMICOLON,
	AND,
	OR
} Separator;

char *check_prog_name(char *filename);
int execute_single_command(char **argv, char **envp);
int run_child(char *prog_name, char **argv, char **envp);
int _exec(char *command, char **envp, Separator n);
int parse_and_exec(char **commands, char **envp, Separator n);
char **split_commands(char *command, const char *delim);
int execute_commands(char *command, char **envp, Separator s);

char *get_command(void);
char **parse_command(char *command);
int check_command(const char *command);
char *search_path(char *filename);
char *get_abs_path(char *filedir, char *filename);
char **parse_path(char *path);
void exit_search_safe(char **paths, char *filepath);

ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
char *_getenv(const char *name);
char *_strtok(char *str, const char *delim);

void (*get_builtin_cmd(char **argv))(char **);
int execute_builtin(char **argv);
void ksh_cd(char **argv);
void ksh_exit(char **argv);
void ksh_setenv(char **argv);
void ksh_unsetenv(char **argv);
void ksh_env(char **argv);

Separator get_next_separator(const char *command);



#endif
