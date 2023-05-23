#ifndef SHELL_H
#define SHELL_H

/* Include necessary header files */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
#include <sys/wait.h>

/* Define constants */
#define MAX_INPUT_SIZE 1024
#define TOKEN_DELIMITER " \t\r\n\a"
#define MAX_TOKENS 100

/**
 * struct shell - A struct that represents a shell instance
 *
 * @input: A pointer to a string containing the user's input
 * @tokens: An array of strings containing the parsed input tokens
 */
typedef struct shell
{
	char *input;
	char *tokens[MAX_TOKENS];
} shell_t;

/* Define function prototypes */
void execute_command(shell_t *shell);
void tokenize(shell_t *shell);
void handle_SIGINT(int sig);
int check_builtins(shell_t *shell);
void trim(char *str);

#endif /* SHELL_H */
