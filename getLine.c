#include "shell.h"

/**
 * my_get_line - to custgetli
 * @str: a str poin
 * @szzStr: def as 1024
 * @reading: the fille be read
 * Return: writ li leng
*/

ssize_t my_get_line(char **str, size_t *szzStr,
FILE *reading)
{
	ssize_t lengthing = 0, starInpt = 0;
	char *strg = NULL, currentC = ' ';

	if (starInpt == 0)
		fflush(reading);
	else
		return (-1);

	strg = malloc(strg_SIZE * sizeof(char));
	if (strg == NULL)
		return (-1);

	while (currentC != '\n')
	{
		if (!my_read_input(&currentC))
		{
			free(strg);
			exit(EXIT_SUCCESS);
		}

		if (starInpt >= strg_SIZE)
			strg = my_re_allocation(strg, starInpt + 1);
		strg[starInpt++] = currentC;
	}

	strg[starInpt] = '\0';
	my_buf_upto(str, szzStr, strg, starInpt);
	lengthing = starInpt;

	if (starInpt != 0)
		starInpt = 0;

	return (lengthing);
}

