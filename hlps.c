#include "shell.h"

/**
 * myint_to_string - intsialaze intger
 * @numbrX: num of inger
 * Return: a character
 */
char *myint_to_string(int numbrX)
{
	int zeroLess = 0, digging = 0, tmppng, i = 0, j = 0;
	char *strringg;

	if (numbrX < 0)
	{
		zeroLess = 1;
		numbrX *= -1;
		digging++;
	}
	tmppng = numbrX;
	while (tmppng > 0)
	{
		digging++;
		tmppng /= 10;
	}
	strringg = (char *) malloc(sizeof(char) * (digging + 1));
	do {
		strringg[i++] = (numbrX % 10) + '0';
		numbrX /= 10;
	} while (numbrX);

	if (zeroLess)
	{
		strringg[i++] = '-';
	}

	j = i - 1;
	i = 0;
	while (i < j)
	{
		char tmp = strringg[i];

		strringg[i] = strringg[j];
		strringg[j] = tmp;
		i++;
		j--;
	}

	strringg[digging] = '\0';
	return (strringg);
}

/**
 * my_digit- digiralyy
 * @y: digitalyy
 * Return: booling
 */
int my_digit(int y)
{
	if (y >= '0' && y <= '9')
		return (1);
	else
		return (0);
}



