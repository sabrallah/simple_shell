#include "shell.h"

/**
 * free_char_array - Frees a char array and its contents.
 * @arr: The char array to free.
 */
void free_char_array(char **arr)
{
	int i;

	if (arr == NULL)
	{
		return;
	}

	for (i = 0; arr[i] != NULL; i++)
	{
		free(arr[i]);
	}

	free(arr);
}

/**
 * handle_signal - Handles signals received by the shell.
 * @sig: The signal to handle.
 */
void handle_signal(int sig)
{
	signal(sig, handle_signal);
}

/**
 * handle_error - Handles errors encountered by the shell.
 * @msg: The error message to print.
 */
void handle_error(char *msg)
{
	perror(msg);
	exit(EXIT_FAILURE);
}
