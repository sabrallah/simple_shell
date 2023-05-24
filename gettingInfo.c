#include "headers.h"
/**
 * my_infodel -  infoPtr initializing struct.
 * @infoPtr: address of struct
 */
void my_infodel(info_t *infoPtr)
{
	infoPtr->arg = NULL;
	infoPtr->argv = NULL;
	infoPtr->path = NULL;
	infoPtr->argc = 0;
}

/**
 * my_setinf - struct info initializing.
 * @infoPtr: address of struct.
 * @avPtr: vector of argument.
 */
void my_setinf(info_t *infoPtr, char **avPtr)
{
	int i = 0;

	infoPtr->fname = avPtr[0];
	if (infoPtr->arg)
	{
		infoPtr->argv = mystrdil(infoPtr->arg, " \t");
		if (!infoPtr->argv)
		{
			infoPtr->argv = malloc(sizeof(char *) * 2);
			if (infoPtr->argv)
			{
				infoPtr->argv[0] = _strdup(infoPtr->arg);
				infoPtr->argv[1] = NULL;
			}
		}
		for (i = 0; infoPtr->argv && infoPtr->argv[i]; i++)
			;
		infoPtr->argc = i;

		resolve_alias(infoPtr);
		my_resolvar(infoPtr);
	}
}

/**
 * my_freinf - info struct infoPtr frees => fields.
 * @infoPtr: address of struct.
 * @allPtr: if freeing all fields gives true.
 */
void my_freinf(info_t *infoPtr, int allPtr)
{
	my_freestr(infoPtr->argv);
	infoPtr->argv = NULL;
	infoPtr->path = NULL;
	if (allPtr)
	{
		if (!infoPtr->cmd_buf)
			free(infoPtr->arg);
		if (infoPtr->env)
			my_listdest(&(infoPtr->env));
		if (infoPtr->history)
			my_listdest(&(infoPtr->history));
		if (infoPtr->alias)
			my_listdest(&(infoPtr->alias));
		my_freestr(infoPtr->environ);
			infoPtr->environ = NULL;
		my_free((void **)infoPtr->cmd_buf);
		if (infoPtr->readfd > 2)
			close(infoPtr->readfd);
		_putchar(BUF_FLUSH);
	}
}

