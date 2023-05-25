#include "shell.h"

/**
 * my_files_exit - if a file exists
 * @pathing: the file to check
 * Return: 1 if the file exists, 0 otherwise
 */
int my_files_exit(const char *pathing)
{
	struct stat bfr;

	if (stat(pathing, &bfr) != 0)
		return (0);
	return (1);
}

