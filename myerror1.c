#include "headers.h"

/**
 * my_strtoint - string converted to an integer.
 * @sPtr: converte the string.
 * Return: returned 0 if the string has no numbers, otherwise
 *       number to be converted error on -1.
 */
int my_strtoint(char *sPtr)
{
	int x = 0;
	unsigned long int resultF = 0;

	if (*sPtr == '+')
		sPtr++;  /* TODO: why does this make main return 255? */
	for (x = 0;  sPtr[x] != '\0'; x++)
	{
		if (sPtr[x] >= '0' && sPtr[x] <= '9')
		{
			resultF *= 10;
			resultF += (sPtr[x] - '0');
			if (resultF > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}
	return (resultF);
}

/**
 * my_erroprint - error message to be printed.
 * @infoPtr: infoPtr struct returned and the parameter.
 * @estrPtr: specified error type containing on a string.
 * Return: 0 if string has no numbers, otherwise number converted
 *        error on -1.
 */
void my_erroprint(info_t *infoPtr, char *estrPtr)
{
	my_printstr(infoPtr->fname);
	my_printstr(": ");
	my_decimprint(infoPtr->line_count, STDERR_FILENO);
	my_printstr(": ");
	my_printstr(infoPtr->argv[0]);
	my_printstr(": ");
	my_printstr(estrPtr);
}

/**
 * my_decimprint - decimal (integer) number (base 10) printed by this function.
 * @in_put: user entry point.
 * @f_d: writeed the filedescriptor to.
 * Return: printed characters number.
 */
int my_decimprint(int in_put, int f_d)
{
	int (*__putchar)(char) = _putchar;
	int x, countInt = 0;
	unsigned int _a_bs_, currentInt;

	if (f_d == STDERR_FILENO)
		__putchar = my_chrtostderr;
	if (in_put < 0)
	{
		_a_bs_ = -in_put;
		__putchar('-');
		countInt++;
	}
	else
		_a_bs_ = in_put;
	currentInt = _a_bs_;
	for (x = 1000000000; x > 1; x /= 10)
	{
		if (_a_bs_ / x)
		{
			__putchar('0' + currentInt / x);
			countInt++;
		}
		currentInt %= x;
	}
	__putchar('0' + currentInt);
	countInt++;

	return (countInt);
}

/**
 * my_convnum - function convertered, itoa clone.
 * @number: the principal number.
 * @baseOn: the base
 * @flagsArgument: the flags argument.
 *
 * Return: returns string each time.
 */
char *my_convnum(long int number, int baseOn, int flagsArgument)
{
	static char *array;
	static char buffer[50];
	char signChar = 0;
	char *ptrChar;
	unsigned long num = number;
	char part1[50] = "0123456789abcdef";
	char part2[50] = "0123456789ABCDEF";

	if (!(flagsArgument & CONVERT_UNSIGNED) && number < 0)
	{
		num = -number;
		signChar = '-';
	}
	array = flagsArgument & CONVERT_LOWERCASE ? part1 : part2;
	ptrChar = &buffer[49];
	*ptrChar = '\0';

	do	{
		*--ptrChar = array[num % baseOn];
		num /= baseOn;
	} while (num != 0);

	if (signChar)
		*--ptrChar = signChar;
	return (ptrChar);
}

/**
 * my_rmcomment - the first instance of '#' with '\0' replaces by function.
 * @bufChar: modify the string address
 *
 * Return: returns 0 every time.
 */
void my_rmcomment(char *bufChar)
{
	int x;

	for (x = 0; bufChar[x] != '\0'; x++)
		if (bufChar[x] == '#' && (!x || bufChar[x - 1] == ' '))
		{
			bufChar[x] = '\0';
			break;
		}
}

