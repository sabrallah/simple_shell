#include "shell.h"

/**
 * my_get_dirct_pat - directory pathing and a command
 * @pathing: The dire path
 * @commanding: The comm name
 *
 * Return: strwith the conca pathing and com nam
 */
char *my_get_dirct_pat(const char *pathing, const char *commanding)
{
	char *lissing = malloc(my_lenstr_get(pathing) +
	my_lenstr_get(commanding) + 2);

	if (!lissing)
		return (NULL);

	my_copy_str(lissing, pathing);
	my_cat_str(lissing, "/");
	my_cat_str(lissing, commanding);

	return (lissing);
}

