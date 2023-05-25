#include "shell.h"

/**
 * my_input_read - std reding function probts
 * starting on the mygetline() function, returning ponter
 * string input.
 * Return:from string input to pointer, || NULL || err || empty line.
 */
char *my_input_read()
{
	char *holdI = NULL;
	size_t allocingS = 0;
	ssize_t readinfT;

	fflush(stdout);
	readinfT = getline(&holdI, &allocingS, stdin);

	if (readinfT == -1)
	{
		free(holdI);
		return (NULL);
	}
	if (readinfT > 0 && holdI[readinfT - 1] == '\n')
	{
		holdI[readinfT - 1] = '\0';
	}
	return (holdI);
}

