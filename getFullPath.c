#include "shell.h"

/**
 * my_full_get_path - full path of a com
 * @commanding: the com
 * Return: ful dir path or NUL
*/

char *my_full_get_path(const char *commanding)
{
	char *conping, *drr, *tkn;

	conping = my_copy_get();
	if (!conping)
		return (NULL);

	drr = NULL;
	tkn = strtok(conping, ":");

	while (tkn != NULL)
	{
		drr = my_get_dirct_pat(tkn, commanding);
		if (!drr)
			break;

		if (my_files_exit(drr) == 1)
		{
			free(conping);
			return (drr);
		}
		else
		{
			free(drr);
			drr = NULL;
			tkn = strtok(NULL, ":");
		}
	}

	free(conping);

	if (my_files_exit(commanding) == 1)
		return ((char *) commanding);

	return (drr);
}

