#include "shell.h"
#include <ctype.h>

/**
 * rtrim - Helper function to remove trailing whitespace
 * @str: The string to trim
 */
void rtrim(char *str)
{
	int i;

	for (i = strlen(str) - 1; i >= 0 && isspace(str[i]); i--)
	;
	str[i + 1] = '\0';
}

/**
 * ltrim - Helper function to remove leading whitespace
 * @str: The string to trim
 */
void ltrim(char *str)
{
	int i, j = 0;

	while (isspace(str[j]))
		j++;

	if (j != 0)
	{
		for (i = 0; str[j] != '\0'; i++, j++)
			str[i] = str[j];
		str[i] = '\0';
	}
}

/**
 * trim - Helper function to remove leading and trailing whitespace
 * @str: The string to trim
 */
void trim(char *str)
{
	rtrim(str);
	ltrim(str);
}

/**
 * error_handler - Helper function to print error messages
 * @message: The error message to print
 */
void error_handler(char *message)
{
	fprintf(stderr, "Error: %s\n", message);
}

/**
 * check_builtins - Helper function to check for built-in commands
 * @shell: Pointer to the shell_t struct
 *
 * Return: 0 if not a built-in, 1 if a built-in was executed, -1 on error
 */
int check_builtins(shell_t *shell)
{
	int result = 0;

	if (strcmp(shell->tokens[0], "exit") == 0)
	{
		exit(EXIT_SUCCESS);
	}
	else if (strcmp(shell->tokens[0], "cd") == 0)
	{
		if (chdir(shell->tokens[1]) != 0)
		{
			perror("Error");
			result = -1;
		}
	}
	else if (strcmp(shell->tokens[0], "help") == 0)
	{
		printf("Display help message\n");
		result = 1;
	}
	else if (strcmp(shell->tokens[0], "history") == 0)
	{
		printf("Display history of commands executed\n");
		result = 1;
	}

	return (result);
}

