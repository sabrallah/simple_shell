#include "shell.h"

/**
 *  my_lenstr_get - handle strringX leng
 * @strringX: the strringX
 * Return: leng
*/

size_t  my_lenstr_get(const char *strringX)
{
	size_t annex = 0;

	while (*strringX != '\0')
	{
		annex++;
		strringX++;
	}
	return (annex);
}

