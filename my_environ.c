#include "headers.h"

/**
 * my_prinenv - current envirnement should be printed
 * @myinfo: arguments potentiels contained by struct. for the maintain
 *          constant function prototype.
 * Return: Always 0
 */
int my_prinenv(info_pass *myinfo)
{
	my_strvalue(myinfo->envList);
	return (0);
}

/**
 * my_getenv - an environ variable value geted
 * @myinfo: potential arguments contained by structure. for to maintain
 * @mynome: var envList mynome
 *
 * Return: a values
 */
char *my_getenv(info_pass *myinfo, const char *mynome)
{
	listing_t *node = myinfo->envList;
	char *y;

	while (node)
	{
		y = my_strstart(node->strChar, mynome);
		if (y && *y)
			return (y);
		node = node->nxt;
	}
	return (NULL);
}

/**
 * my_initenv - new environment variable initialized,
 *             or changed an existing one
 * @myinfo: potential arguments contained by structures. for the maintain
 *        constant function prototype.
 *  Return: Always 0
 */
int my_initenv(info_pass *myinfo)
{
	if (myinfo->argcInt != 3)
	{
		my_printstr("Incorrect number of arguements\n");
		return (1);
	}
	if (my_envsett(myinfo, myinfo->argvChar[1], myinfo->argvChar[2]))
		return (0);
	return (1);
}

/**
 * my_rmenv - eliminate a variable envirnment
 * @myinfo: potential argument contained by structures. for the maintain
 *        constant functions prototype.
 * Return: Always 0
 */
int my_rmenv(info_pass *myinfo)
{
	int y;

	if (myinfo->argcInt == 1)
	{
		my_printstr("Too few arguements.\n");
		return (1);
	}
	for (y = 1; y <= myinfo->argcInt; y++)
		my_delenv(myinfo, myinfo->argvChar[y]);

	return (0);
}

/**
 * my_popenvir - envList populated a linked list
 * @myinfo: potential arguments contained by structures. Used to maintain
 *          constant function prototype.
 * Return: Always 0
 */
int my_popenvir(info_pass *myinfo)
{
	listing_t *node = NULL;
	size_t y;

	for (y = 0; environ[y]; y++)
		my_appen_nod(&node, environ[y], 0);
	myinfo->envList = node;
	return (0);
}
