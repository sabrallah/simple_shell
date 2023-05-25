#include "shell.h"

/**
 * my_cat_str - containes character
 * @dess: desting character
 * @sourssing: character store
 * Return: character routing
 */
char *my_cat_str(char *dess, const char *sourssing)
{
	size_t lenthing = my_lenstr_get(dess);

	my_copy_str(dess + lenthing, sourssing);

	return (dess);
}

