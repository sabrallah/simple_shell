#include "shell.h"

/**
 * change_dir - Built-in command to change directory
 * @shell: Pointer to the shell_t struct
 *
 * Return: 0 on success, 1 on failure
 */
int change_dir(shell_t *shell)
{
	if (chdir(shell->tokens[1]) == -1)
	{
		perror(shell->tokens[1]);
		return (1);
	}

	return (0);
}

/**
 * exit_shell - Built-in command to exit shell
 */
void exit_shell(void)
{
	exit(0);
}

/**
 * print_help - Built-in command to display help message
 */
void print_help(void)
{
	printf("A simple shell program.\n");
}

/**
 * print_history - Built-in command to display command history
 */
void print_history(void)
{
	printf("Command history.\n");
}

/**
 * handle_builtins - Function to check for and handle built-in commands
 * @shell: Pointer to the shell_t struct
 *
 * Return: 1 if command is a built-in, 0 otherwise
 */
int handle_builtins(shell_t *shell)
{
	/* Check if command is a built-in */
	if (strcmp(shell->tokens[0], "cd") == 0)
	{
		return (change_dir(shell));
	}
	else if (strcmp(shell->tokens[0], "exit") == 0)
	{
		exit_shell();
	}
	else if (strcmp(shell->tokens[0], "help") == 0)
	{
		print_help();
	}
	else if (strcmp(shell->tokens[0], "history") == 0)
	{
		print_history();
	}
	else
	{
		return (0);
	}

	return (1);
}

