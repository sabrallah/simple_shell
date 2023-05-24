#include "headers.h"

/**
 **my_strlimit - string to be copied.
 *@destPtr: to copies the destination string.
 *@srcPtr: the string source.
 *@nInt: copies the characters amount.
 *
 *Return: the string that concatenated.
 */
char *my_strlimit(char *destPtr, char *srcPtr, int nInt)
{
	int x, y;
	char *sPtr = destPtr;

	x = 0;
	while (srcPtr[x] != '\0' && x < nInt - 1)
	{
		destPtr[x] = srcPtr[x];
		x++;
	}
	if (x < nInt)
	{
		y = x;
		while (y < nInt)
		{
			destPtr[y] = '\0';
			y++;
		}
	}
	return (sPtr);
}

/**
 **my_strconc - Multiple strings concatenates.
 *@destPtr: string one.
 *@srcPtr: string two.
 *@nInt: use maximally bytes amount.
 *Return: string that concatenated.
 */
char *my_strconc(char *destPtr, char *srcPtr, int nInt)
{
	int x, y;
	char *sPtr = destPtr;

	x = 0;
	y = 0;
	while (destPtr[x] != '\0')
		x++;
	while (srcPtr[y] != '\0' && y < nInt)
	{
		destPtr[x] = srcPtr[y];
		x++;
		y++;
	}
	if (y < nInt)
		destPtr[x] = '\0';
	return (sPtr);
}

/**
 **my_strfin - locates a character in a string
 *@sPtr: the string to be parsed
 *@ch: looking for the character
 *Return: the memory area sPtr from pointer (sPtr).
 */
char *my_strfin(char *sPtr, char ch)
{
	do {
		if (*sPtr == ch)
			return (sPtr);
	} while (*sPtr++ != '\0');

	return (NULL);
}
