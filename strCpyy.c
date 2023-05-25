#include "shell.h"

/**
 * my_copy_str - resoursing
 * @dss: array of character
 * @sourssing: chracter[0]
 * Return: coping
*/

char *my_copy_str(char *dss, const char *sourssing)
{
	char *pointt = dss;

	while (*sourssing != '\0')
	{
		*pointt++ = *sourssing++;
	}
	*pointt = '\0';
	return (dss);
}

