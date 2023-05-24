#include "shell.h"

/**
 * read_line - Read a line of input from stdin.
 *
 * This function reads a line of input from standard input using the getline()
 * function. It dynamically allocates memory to store the input string and
 * adjusts the size of the buffer as needed. If the end of file (EOF) is
 * reached, the function prints a newline character and exits with success.
 *
 * Return: A pointer to the input string, or NULL if an error occurs.
 */
char *read_line(void)
{
	char *line = NULL;
	size_t bufsize = 0;

	if (getline(&line, &bufsize, stdin) == -1)
	{
		/* Handle EOF */
		printf("\n");
		exit(EXIT_SUCCESS);
	}

	return (line);
}

