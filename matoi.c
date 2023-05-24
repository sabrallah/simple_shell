#include "headers.h"

/**
 * myInteractive - if shell is myInteractive mode returns true
 * @myinfo: struct memory address
 *
 * Return: 1 if mode myInteractive , 0 otherwise
 */
int myInteractive(info_t *myinfo)
{
	return (isatty(STDIN_FILENO) && myinfo->readfd <= 2);
}

/**
 * mydelimiter - checks if is a delimeter character
 * @y: check to the char
 * @mydelim: the string delimeter
 * Return: 1 if true, 0 if false
 */
int mydelimiter(char y, char *mydelim)
{
	while (*mydelim)
		if (*mydelim++ == y)
			return (1);
	return (0);
}

/**
 * myalphabetic - for checks character alphabetic
 * @y: input to The character
 * Return: 1 if y is alphabetic, 0 otherwise
 */

int myalphabetic(int y)
{
	if ((y >= 'a' && y <= 'z') || (y >= 'A' && y <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 * my_covert_int - string to converts to an integer
 * @m: to be converted a string
 * Return: 0 if no number in strings, converted number otherwise
 */

int my_covert_int(char *m)
{
	int y, signale = 1, yflag = 0, youtput;
	unsigned int yresult = 0;

	for (y = 0; m[y] != '\0' && yflag != 2; y++)
	{
		if (m[y] == '-')
			signale *= -1;

		if (m[y] >= '0' && m[y] <= '9')
		{
			yflag = 1;
			yresult *= 10;
			yresult += (m[y] - '0');
		}
		else if (yflag == 1)
			yflag = 2;
	}

	if (signale == -1)
		youtput = -yresult;
	else
		youtput = yresult;

	return (youtput);
}

