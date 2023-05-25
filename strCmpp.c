#include "shell.h"

/**
 * my_cmp_strn - Comparing chracter string
 * @one:first character
 * @two: last character
 * Return: int
 */
int my_cmp_strn(const char *one, const char *two)
{
	while (*one == *two && *one != '\0')
	{
		one++;
		two++;
	}

	return ((int)(*one) - (int)(*two));
}
