#include "shell.h"

/**
 * my_free_world - list of wrding.
 * @wrding: Pointer of strings.
 * @numberW: wrding in the arrays.
 * frees each individual string in the array using the
 * free() function and finally frees the array itself using free().
 */
void my_free_world(char **wrding, int numberW)
{
	int x;

	if (wrding == NULL)
		return;
	for (x = 0; x < numberW; x++)
	{
		if (wrding[x] != NULL)
		{
			free(wrding[x]);
			wrding[x] = NULL;
		}
	}
	free(wrding);
}

