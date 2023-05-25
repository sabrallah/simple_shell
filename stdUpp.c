#include "shell.h"

/**
 * my_dupl_strin - character dest.
 * @strr: arr of chracter.
 * Return: none lenthing.
 */
char *my_dupl_strin(const char *strr)
{
	size_t lenthing = my_lenstr_get(strr), i;
	char *deepping = malloc(lenthing + 1);

	if (deepping)
	{
		for (i = 0; i < lenthing; i++)
			deepping[i] = strr[i];
		deepping[lenthing] = '\0';
	}

	return (deepping);
}

