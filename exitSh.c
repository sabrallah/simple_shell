#include "shell.h"

/**
 * my_handle_exit -  exit built-in command.
 * @wordArray: commanding
 * @uInput: input user.
 * @shellN: program nome
 * @contre: contre commanders
 * @nX: numbers of commanders
 * Return: void.
 */
void my_handle_exit(char **wordArray, char *uInput,
char *shellN, int contre, int nX)
{
	int exitTT, i = 0;

	if (wordArray[1] == NULL)
	{
		free(uInput);
		my_free_world(wordArray, nX);
		exit(EXIT_SUCCESS);
	}

	while (wordArray[1][i])
	{
		if (my_digit(wordArray[1][i++]) == 0)
		{
			my_exerr(wordArray, contre, shellN);
			break;
		}
		else
		{
			exitTT = my_atoy(wordArray[1]);
			free(uInput);
			my_free_world(wordArray, nX);
			exit(exitTT);
		}
	}

}

