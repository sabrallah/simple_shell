#include "shell.h"
#include <errno.h>
/**
 * execute_command - forks a child process to execute a command
 * @args: a null-terminated array of arguments, including the command
 *
 * Return: 1 on success, or -1 on error
 */
int execute_command(char **args)
{	pid_t pid;
	int status;

	if (strcmp(args[0], "exit") == 0)
	{
		exit(0);
	}
	pid = fork();
	if (pid == 0)
	{execvp(args[0], args);
		if (errno == ENOENT)
		{char *path_env = getenv("PATH");
		char *path = strtok(path_env, ":");

			while (path != NULL)
			{char *command_path = malloc(strlen(path) + strlen(args[0]) + 2);

				sprintf(command_path, "%s/%s", path, args[0]);
				execv(command_path, args);
				free(command_path); /* Free memory allocated by malloc */
				path = strtok(NULL, ":");
			}
		fprintf(stderr, "hsh: command not found: %s\n", args[0]);
		}
		else
		{
			perror("hsh");
		}
	exit(1);
	}
	else if (pid < 0)
	{
		perror("hsh");
	}
	else
	{
		do {
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	return (1);
}
