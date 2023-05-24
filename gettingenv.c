#include "headers.h"

/**
 * my_envcopy - returned array of strings copy version of our environ.
 * @infoPtr: contained structure potential arguments, maintain use
 *           prototype of constant function.
 * Return: returns 0 each time.
 */
char **my_envcopy(info_t *infoPtr)
{
	if (!infoPtr->environ || infoPtr->env_changed)
	{
		infoPtr->environ = my_conv_strin(infoPtr->env);
		infoPtr->env_changed = 0;
	}

	return (infoPtr->environ);
}

/**
 * my_delenv - Remove an environment variable
 * @infoPtr: contained structure of potential arguments, used to maintain
 *         prototype constant function.
 *  Return: if delete gives 1, otherwise gives 0.
 * @varPtr: env var property of string.
 */
int my_delenv(info_t *infoPtr, char *varPtr)
{
	list_t *node = infoPtr->env;
	size_t x = 0;
	char *ptr;

	if (!node || !varPtr)
		return (0);

	while (node)
	{
		ptr = my_strstart(node->str, varPtr);
		if (ptr && *ptr == '=')
		{
			infoPtr->env_changed = my_remov_node_index(&(infoPtr->env), x);
			x = 0;
			node = infoPtr->env;
			continue;
		}
		node = node->next;
		x++;
	}
	return (infoPtr->env_changed);
}

/**
 * my_envsett - new environment variable as Initialized,
 *              one existing to be modify
 * @infoPtr: potential arguments that containing on a structure
 * @varPtr: property var as env string
 * @valuePtr: string, env ,var and value
 *  Return: returns 0 each time.
 */
int my_envsett(info_t *infoPtr, char *varPtr, char *valuePtr)
{
	char *bufChar = NULL;
	list_t *node;
	char *ptr;

	if (!varPtr || !valuePtr)
		return (0);

	bufChar = malloc(_strlen(varPtr) + _strlen(valuePtr) + 2);
	if (!bufChar)
		return (1);
	_strcpy(bufChar, varPtr);
	_strcat(bufChar, "=");
	_strcat(bufChar, valuePtr);
	node = infoPtr->env;
	while (node)
	{
		ptr = my_strstart(node->str, varPtr);
		if (ptr && *ptr == '=')
		{
			free(node->str);
			node->str = bufChar;
			infoPtr->env_changed = 1;
			return (0);
		}
		node = node->next;
	}
	my_appen_nod(&(infoPtr->env), bufChar, 0);
	free(bufChar);
	infoPtr->env_changed = 1;
	return (0);
}
