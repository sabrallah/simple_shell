#include "shell.h"

/**
 * handle_SIGINT - Signal handler function for SIGINT
 * @sig: The signal number
 */
/* Signal handler function for SIGINT */
void handle_SIGINT(int sig)
{
	(void) sig;
	write(STDOUT_FILENO, "\n$ ", 3);
	fflush(stdout);
}

