#include "headers.h"
/**
 * my_printstr - Send input string to the output.
 * @strPtr: Print the string.
 *
 * Return: None thing.
 */
void my_printstr(char *strPtr)
{
	int i = 0;

	if (!strPtr)
		return;
	while (strPtr[i] != '\0')
	{
		my_chrtostderr(strPtr[i]);
		i++;
	}
}

/**
 * my_chrtostderr - Writed ch character to stderr.
 * @ch: Print The character.
 *
 * Return: When success 1.
 * If error, return -1, appropriately sted by errno.
 */
int my_chrtostderr(char ch)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (ch == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(2, buf, i);
		i = 0;
	}
	if (ch != BUF_FLUSH)
		buf[i++] = ch;
	return (1);
}

/**
 * my_chrtofd - ch character writed to given fd
 * @ch: printed The character
 * @f_d: writed filedescriptor to
 *
 * Return: If success 1.
 * If error, return -1, appropriately seted by errno.
 */
int my_chrtofd(char ch, int f_d)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (ch == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(f_d, buf, i);
		i = 0;
	}
	if (ch != BUF_FLUSH)
		buf[i++] = ch;
	return (1);
}

/**
 * my_strtofd - input string to be printed
 * @strPtr: theto string to be printed
 * @f_d: write the filedescriptor to
 *
 * Return: chars put number
 */
int my_strtofd(char *strPtr, int f_d)
{
	int i = 0;

	if (!strPtr)
		return (0);
	while (*strPtr)
	{
		i += my_chrtofd(*strPtr++, f_d);
	}
	return (i);
}
