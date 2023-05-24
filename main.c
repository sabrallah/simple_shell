#include "shell.h"

/**
 * main - Entry point for Simple Shell
 *
 * Description:
 * Runs a simple shell program that prompts the user for input,
 * reads the input, parses it into arguments, and executes the command.
 * The shell can also handle basic signal handling for SIGINT.
 *
 * Return: EXIT_SUCCESS on success, otherwise an error code.
 */
int main(void)
{
	char *line;
	char **args;
	int status;

	/* Register signal handler */
	signal(SIGINT, handle_signal);

	do {
		display_prompt();
		line = read_line();
		args = parse_line(line);
		status = execute_command(args);

		/**
		 * free(line);
		 * free_char_array(args);
		 */
	} while (status);

	return (EXIT_SUCCESS);
}
