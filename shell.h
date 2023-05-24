#ifndef SHELL_H
#define SHELL_H

/* Libraries */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <string.h>
#include <fcntl.h>

/* Macros */
#define PROMPT "$ "
#define DELIM " \n\t\r\a"
#define BUFSIZE 1024

extern char **environ;

/* Builtin Functions */
int execute_builtin(char **args);
int _exit_shell(char **args);
int print_env(void);


/* Helper Functions */
char **parse_line(char *line);
int execute_command(char **args);
void free_char_array(char **arr);
void handle_signal(int sig);
void handle_error(char *msg);
void display_prompt(void);
char *read_line(void);

#endif /* SHELL_H */

