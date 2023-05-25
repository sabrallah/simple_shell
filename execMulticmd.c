#include "shell.h"

/**
 * my_exec_cmd - Execute  by semicolons
 * @uInput: nput string containing the commands
 * @shell: program names
 * @contre: count monad
 * Return: error code
 */
int my_exec_cmd(char *uInput, char *shell, int contre)
{
	int cmdNumber, wordsNumber, i, exitCodding;
	char **cmdArray, **wordArray;

	cmdArray = split_string(uInput, ";", &cmdNumber);
	if (cmdArray == NULL)
	{
		printf("Error splitting user input\n");
		return (errno);
	}

	for (i = 0; i < cmdNumber; i++)
	{
		wordArray = split_string(cmdArray[i], " \t\r\n", &wordsNumber);
		if (wordArray == NULL)
		{
			perror("Error splitting command string\n");
			continue;
		}
		if (wordsNumber == 0)
		{
			my_free_world(cmdArray, cmdNumber);
			my_free_world(wordArray, cmdNumber);
			return (0);
		}
		if (my_cmp_strn(wordArray[0], "exit") == 0)
		{
			my_free_world(cmdArray, cmdNumber);
			my_handle_exit(wordArray, uInput,
			shell, contre, wordsNumber);
		}
		exitCodding = my_execute_forking(wordArray, uInput, shell,
		contre, wordsNumber);
		my_free_world(wordArray, wordsNumber);
	}

	my_free_world(cmdArray, cmdNumber);
	return (exitCodding);
}

