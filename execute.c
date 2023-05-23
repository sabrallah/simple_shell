#include "shell.h"

/**
 * execute_command - Function to execute command
 * @shell: Pointer to the shell_t struct
 */
void execute_command(shell_t *shell)
{
	pid_t pid;
	int status;

	if (check_builtins(shell))
	{
		return;
	}

	pid = fork();
	if (pid == 0)
	{
	/* Child process */

	/* Execute command */
	if (execvp(shell->tokens[0], shell->tokens) == -1)
	{
		perror("Error");
		exit(EXIT_FAILURE);
	}

	}
	else if (pid < 0)
	{
	/* Forking error */

	perror("Error");
	}
	else
	{
		/* Parent process */
		do {
			if (waitpid(pid, &status, WUNTRACED) == -1)
			{
				perror("Error");
			}
		}
	while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
}

