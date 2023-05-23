#include "shell.h"

/**
 * main - Entry point for the shell program
 *
 * Return: Always 0
 */
int main(void)
{
	shell_t *shell;
	int status = 1;

	signal(SIGINT, handle_SIGINT);

	while (status)
	{
		printf("$ ");
		fflush(stdout);

		shell = (shell_t *) malloc(sizeof(shell_t));
		if (shell == NULL)
		{
			perror("Error: Allocation failed!");
			exit(EXIT_FAILURE);
		}

		shell->input = (char *) malloc(MAX_INPUT_SIZE * sizeof(char));
		if (shell->input == NULL)
		{
			perror("Error: Allocation failed!");
			exit(EXIT_FAILURE);
		}

	fgets(shell->input, MAX_INPUT_SIZE, stdin);

	tokenize(shell);
	execute_command(shell);

	free(shell->input);
	free(shell);
	}

	return (0);
}

