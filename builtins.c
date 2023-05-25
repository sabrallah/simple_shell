#include "shell.h"
#include <unistd.h>
#include <stdlib.h>

/**
 * execute_builtin - executes built-in shell commands
 *
 * @args: arguments array
 * Return: 0 on success, -1 on failure
 */
int execute_builtin(char **args)
{
if (strcmp(args[0], "exit") == 0)
	{
		free_char_array(args); /** Free memory allocated for args */
		exit(0);
	}
	else if (strcmp(args[0], "env") == 0)
	{
		int result = print_env();
		free_char_array(args); /** Free memory allocated for args */
		return result;
	}

	free_char_array(args); /** Free memory allocated for args */
	return -1;
}

/**
 * _exit_shell - exits the shell
 *
 * @args: arguments array
 * Return: void
 */
int _exit_shell(char **args)
{
if (args[1] != NULL)
	{
		exit(atoi(args[1]));
	}

	free_char_array(args); /** Free memory allocated for args **/
	exit(EXIT_SUCCESS);
}

/**
 * print_env - prints the environment variables
 *
 * Return: 1 on success
 */
int print_env(void)
{
	char **env = environ;

	while (*env)
	{
		printf("%s\n", *env++);
	}
	return (1);
}

