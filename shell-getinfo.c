#include "headers.h"
/**
 * my_infodel -  infoPtr initializing struct.
 * @infoPtr: address of struct
 */
void my_infodel(info_pass *infoPtr)
{
	infoPtr->argChar = NULL;
	infoPtr->argvChar = NULL;
	infoPtr->pathChar = NULL;
	infoPtr->argcInt = 0;
}

/**
 * my_setinf - struct info initializing.
 * @infoPtr: address of struct.
 * @avPtr: vector of argument.
 */
void my_setinf(info_pass *infoPtr, char **avPtr)
{
	int i = 0;

	infoPtr->fnameChar = avPtr[0];
	if (infoPtr->argChar)
	{
		infoPtr->argvChar = mystrdil(infoPtr->argChar, " \t");
		if (!infoPtr->argvChar)
		{
			infoPtr->argvChar = malloc(sizeof(char *) * 2);
			if (infoPtr->argvChar)
			{
				infoPtr->argvChar[0] = _strdup(infoPtr->argChar);
				infoPtr->argvChar[1] = NULL;
			}
		}
		for (i = 0; infoPtr->argvChar && infoPtr->argvChar[i]; i++)
			;
		infoPtr->argcInt = i;

		resolve_alias(infoPtr);
		my_resolvar(infoPtr);
	}
}

/**
 * my_freinf - info struct infoPtr frees => fields.
 * @infoPtr: address of struct.
 * @allPtr: if freeing all fields gives true.
 */
void my_freinf(info_pass *infoPtr, int allPtr)
{
	my_freestr(infoPtr->argvChar);
	infoPtr->argvChar = NULL;
	infoPtr->pathChar = NULL;
	if (allPtr)
	{
		if (!infoPtr->cmd_bufChar)
			free(infoPtr->argChar);
		if (infoPtr->envList)
			my_listdest(&(infoPtr->envList));
		if (infoPtr->historyList)
			my_listdest(&(infoPtr->historyList));
		if (infoPtr->aliasList)
			my_listdest(&(infoPtr->aliasList));
		my_freestr(infoPtr->environChar);
			infoPtr->environChar = NULL;
		my_free((void **)infoPtr->cmd_bufChar);
		if (infoPtr->readfdInt > 2)
			close(infoPtr->readfdInt);
		_putchar(BUF_FLUSH);
	}
}

