#include "headers.h"

/**
 * my_envcopy - returned array of strings copy version of our environ.
 * @infoPtr: contained structure potential arguments, maintain use
 *           prototype of constant function.
 * Return: returns 0 each time.
 */
char **my_envcopy(info_pass *infoPtr)
{
	if (!infoPtr->environChar || infoPtr->env_changedInt)
	{
		infoPtr->environChar = my_conv_strin(infoPtr->envList);
		infoPtr->env_changedInt = 0;
	}

	return (infoPtr->environChar);
}

/**
 * my_delenv - Remove an environment variable
 * @infoPtr: contained structure of potential arguments, used to maintain
 *         prototype constant function.
 *  Return: if delete gives 1, otherwise gives 0.
 * @varPtr: env var property of string.
 */
int my_delenv(info_pass *infoPtr, char *varPtr)
{
	listing_t *node = infoPtr->envList;
	size_t x = 0;
	char *ptr;

	if (!node || !varPtr)
		return (0);

	while (node)
	{
		ptr = my_strstart(node->strChar, varPtr);
		if (ptr && *ptr == '=')
		{
			infoPtr->env_changedInt = my_remov_node_index(&(infoPtr->envList), x);
			x = 0;
			node = infoPtr->envList;
			continue;
		}
		node = node->nxt;
		x++;
	}
	return (infoPtr->env_changedInt);
}

/**
 * my_envsett - new environment variable as Initialized,
 *              one existing to be modify
 * @infoPtr: potential arguments that containing on a structure
 * @varPtr: property var as env string
 * @valuePtr: string, env ,var and value
 *  Return: returns 0 each time.
 */
int my_envsett(info_pass *infoPtr, char *varPtr, char *valuePtr)
{
	char *bufChar = NULL;
	listing_t *node;
	char *ptr;

	if (!varPtr || !valuePtr)
		return (0);

	bufChar = malloc(_strlen(varPtr) + _strlen(valuePtr) + 2);
	if (!bufChar)
		return (1);
	_strcpy(bufChar, varPtr);
	_strcat(bufChar, "=");
	_strcat(bufChar, valuePtr);
	node = infoPtr->envList;
	while (node)
	{
		ptr = my_strstart(node->strChar, varPtr);
		if (ptr && *ptr == '=')
		{
			free(node->strChar);
			node->strChar = bufChar;
			infoPtr->env_changedInt = 1;
			return (0);
		}
		node = node->nxt;
	}
	my_appen_nod(&(infoPtr->envList), bufChar, 0);
	free(bufChar);
	infoPtr->env_changedInt = 1;
	return (0);
}

