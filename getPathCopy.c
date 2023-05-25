#include "shell.h"

/**
 * my_copy_get - take a cop of pt env va
 * Return: A ne allo str cont a cop of the ptt var,
 * or NULL.
 */
char *my_copy_get()
{
	char *ptt = getenv("PATH");
	char *coping;

	if (!ptt)
		return (NULL);

	coping = my_dupl_strin(ptt);
	if (!coping)
		return (NULL);

	return (coping);
}

