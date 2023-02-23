
# simple_shell
This is an implementation of a simple UNIX command interpreter written as part of the low-level programming at ALX SWE.

## Description

This is a simple UNIX sommand language interpreter that reads commands from the standard output or a file and executes the command. This simple shell is based on bash(Bourne Again shell)


### Enviroment

<!-- ubuntu -->
<a href="https://ubuntu.com/" target="_blank"> <img height="" src="https://img.shields.io/static/v1?label=&message=Ubuntu&color=E95420&logo=Ubuntu&logoColor=E95420&labelColor=2F333A" alt="Suite CRM"></a> OS: Ubuntu 20.04 LTS
<!-- bash -->
<a href="https://www.gnu.org/software/bash/" target="_blank"> <img height="" src="https://img.shields.io/static/v1?label=&message=GNU%20Bash&color=4EAA25&logo=GNU%20Bash&logoColor=4EAA25&labelColor=2F333A" alt="terminal"></a>
<!-- c -->
<a href="https://www.cprogramming.com/" target="_blank"><img src="https://img.shields.io/static/v1?label=&message=C%20Language&color=5C6BC0&logo=c&logoColor=A8B9CC&labelColor=2F333A" alt="C Low level programming language"></a> Language: C
Compiler: gcc 9.3.0
<!-- vim -->
<a href="https://www.vim.org/" target="_blank"> <img height="" src="https://img.shields.io/static/v1?label=&message=Vim&color=019733&logo=Vim&logoColor=019733&labelColor=2F333A" alt="Suite CRM"></a> Editor: VIM 8.1.2269
<!-- git -->
<a href="https://git-scm.com/" target="_blank"> <img height="" src="https://img.shields.io/static/v1?label=&message=Git&color=F05032&logo=Git&logoColor=F05032&labelColor=2F333A" alt="git distributed version control system"></a> Control version: Git
<!-- github -->
<a href="https://github.com" target="_blank"> <img height="" src="https://img.shields.io/static/v1?label=&message=GitHub&color=181717&logo=GitHub&logoColor=f2f2f2&labelColor=2F333A" alt="Github"></a>

Style guidelines: [Betty style](https://github.com/holbertonschool/Betty/wiki)

## General requirements.

* Allowed editors: vi, vim, emacs
* All your files will be compiled on 'Ubuntu 14.04 LTS'
* Your C programs and functions will be compiled with 'gcc 4.8.4' using the flags '-Wall -Werror -Wextra and -pedantic
* Your code should use the Betty style. It will be checked using betty-style.pl and betty-doc.pl'
* No more than 5 functions per file
* All your header files should be include guarded
* This shell should not have any memory leaks
* Unless specified otherwise, your program must have the exact same output as sh (/bin/sh) as well as the exact same error output.

## Installation

* [Fork](https://docs.github.com/en/get-started/quickstart/fork-a-repo) the [repository](https://github.com/thatboyreegan/simple_shell).
* [clone](https://docs.github.com/en/repositories/creating-and-managing-repositories/cloning-a-repository) the repository to your local machine.
* Change into the repository 'cd simple_shell'
* Compile the program using the command: 'gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh'
* Type in '_./hsh_' to run the executable.


## Example.

if you run 
> ls -la

Result:
![example](C:\Users\HP\OneDrive\Pictures\Camera Roll\Screenshot 2023-02-23 195947.png)


## Files
|File|Description|
|---|---|
|[AUTHORS](https://github.com/thatboyreegan/simple_shell/blob/main/AUTHORS)|Authors of the project|
|[README.md](https://github.com/thatboyreegan/simple_shell/blob/main/README.md)|Information about the project|
|[_getenv.c](https://github.com/thatboyreegan/simple_shell/blob/main/_getenv.c)|Gets the environment variable|
|[_strtok.c](https://github.com/thatboyreegan/simple_shell/blob/main/_strtok.c)|Tokenizes the string|
|[builtins.c](https://github.com/thatboyreegan/simple_shell/blob/main/builtins.c)|Builtin Commands|
|[check_command.c](https://github.com/thatboyreegan/simple_shell/blob/main/check_command.c)|Checks for command|
|[check_prog_name.c](https://github.com/thatboyreegan/simple_shell/blob/main/check_prog_name.c)|Check for name|
|[error.c](https://github.com/thatboyreegan/simple_shell/blob/main/error.c)|Handles all errors|
|[execute_all_commands.c](https://github.com/thatboyreegan/simple_shell/blob/main/execute_all_commands.c)|Executes all functions|
|[execute_cmd.c](https://github.com/thatboyreegan/simple_shell/blob/main/execute_cmd.c)|Executes single commands |
|[get_command.c](https://github.com/thatboyreegan/simple_shell/blob/main/get_command.c)| Gets a command|
|[get_next_separator.c](https://github.com/thatboyreegan/simple_shell/blob/main/get_next_separator.c)|Grts the next separator|
|[initialize_shell_vars.c](https://github.com/thatboyreegan/simple_shell/blob/main/initialize_shell_vars.c)|Initializes a struct|
|[ksh_cd.c](https://github.com/thatboyreegan/simple_shell/blob/main/ksh_cd.c)| cd command|
|[ksh_env.c](https://github.com/thatboyreegan/simple_shell/blob/main/ksh_env.c)|env command|
|[khs_exit.c](https://github.com/thatboyreegan/simple_shell/blob/main/ksh_exit.c)|Exit builtin|
|[ksh_setenv_unsetenv.c](https://github.com/thatboyreegan/simple_shell/blob/main/ksh_setenv_unsetenv.c)|Set and unset environment variables|
|[main.c](https://github.com/thatboyreegan/simple_shell/blob/main/main.c)|Entry point to the program|
|[main.h](https://github.com/thatboyreegan/simple_shell/blob/main/main.h)|Prototypes of functions and headers.|
|[parse_and_exec.c](https://github.com/thatboyreegan/simple_shell/blob/main/parse_and_exec.c)|executes command as given|
|[parse_command.c](https://github.com/thatboyreegan/simple_shell/blob/main/parse_command.c)|tokenize command entered|
|[remove_comment.c](https://github.com/thatboyreegan/simple_shell/blob/main/remove_comment.c)|Removes comment from command to be executed|
|[search.c](https://github.com/thatboyreegan/simple_shell/blob/main/search.c)|search absolute filepath|
|[signal_handler.c](https://github.com/thatboyreegan/simple_shell/blob/main/signal_handler.c)|Handles signals|
|[Split_commands.c](https://github.com/thatboyreegan/simple_shell/blob/main/split_commands.c)|Splits a command to two srings|



## Contirubutors
* [Brian Kimathi](https://github.com/bryokim)
* [Reagan Odhiambo](https://github.com/thatboyreegan)

## Acknowlegdment

This program emulates some of the basic functionalities of the bash. The man pages were used extensively in the writing of this program.

This program was written as a part of the curriculum for ALX SWE. 