#include "shell.h"

/**
 * my_execute_bin - taking /bin/ls
 * @wordArray: arr  commands
 * Return: void
*/
void my_execute_bin(char **wordArray)
{
	pid_t pidding;
	int current;

	pidding = fork();
	if (pid == 0)
	{
		my_execmdwithexecve("/bin/ls", wordArray);
		perror("Error executing command\n");
		exit(100);
	}
	else if (pidding < 0)
	{
		perror("Error forking");
		return;
	}
	else
		waitpid(pidding, &current, 0);
}

/**
 * my_execute_forking - executes  fork-exec
 * @wordArray: arr  commands
 * @uInput: user prompt
 * @shellN: name program
 * @cntrr: monad counter
 * @n: ------------------
 * @uInput: _______________
 * Return: code erro
*/

int my_execute_forking(char **wordArray, char *uInput,
char *shellN, int cntrr, int n)
{
	char *commanding = NULL, *cXmd = NULL, *crr = NULL;
	pid_t pidding;
	int current, xCodding;

	if (wordArray)
	{
		commanding = wordArray[0];
		if (my_cmp_str(commanding, "/bin/ls") == 0)
		{
			my_execute_bin(wordArray);
			return (0);
		}
		if (my_handle_cmd(wordArray, uInput, shellN, cntrr, n) == 1)
			return (0);
		cXmd = my_full_get_path(commanding);
		if (!cXmd)
		{
			crr = myint_to_string(cntrr);
			if (!my_valid_word(commanding))
				my_print_err(crr, shellN, NULL, "not found\n");
			else
				my_print_err(crr, shellN, commanding, "not found\n");
			free(crr);
			return (127);
		}
		pidding = fork();
		if (pidding == 0)
			my_execmdwithexecve(cXmd, wordArray);
		else if (pidding < 0)
			return (errno);
		my_waitkidproce(pidding, &current);
		if (WIFEXITED(current))
			xCodding = (WEXITSTATUS(current));
	}
	if (my_cmp_str(*wordArray, "./", 2) != 0
	&& my_cmp_str(*wordArray, "/", 1) != 0)
		free(cXmd);

	return (xCodding);
}

