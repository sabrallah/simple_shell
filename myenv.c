#include "headers.h"

/**
 * my_prinenv - current envirnement should be printed
 * @myinfo: arguments potentiels contained by struct. for the maintain
 *          constant function prototype.
 * Return: Always 0
 */
int my_prinenv(info_t *myinfo)
{
	my_strvalue(myinfo->env);
	return (0);
}

/**
 * my_getenv - an environ variable value geted
 * @myinfo: potential arguments contained by structure. for to maintain
 * @mynome: var env mynome
 *
 * Return: a values
 */
char *my_getenv(info_t *myinfo, const char *mynome)
{
	list_t *node = myinfo->env;
	char *y;

	while (node)
	{
		y = my_strstart(node->str, mynome);
		if (y && *y)
			return (y);
		node = node->next;
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
int my_initenv(info_t *myinfo)
{
	if (myinfo->argc != 3)
	{
		my_printstr("Incorrect number of arguements\n");
		return (1);
	}
	if (my_envsett(myinfo, myinfo->argv[1], myinfo->argv[2]))
		return (0);
	return (1);
}


/**
 * my_rmenv - eliminate a variable envirnment
 * @myinfo: potential argument contained by structures. for the maintain
 *        constant functions prototype.
 * Return: Always 0
 */
int my_rmenv(info_t *myinfo)
{
	int y;

	if (myinfo->argc == 1)
	{
		my_printstr("Too few arguements.\n");
		return (1);
	}
	for (y = 1; y <= myinfo->argc; y++)
		my_delenv(myinfo, myinfo->argv[y]);

	return (0);
}


/**
 * my_popenvir - env populated a linked list
 * @myinfo: potential arguments contained by structures. Used to maintain
 *          constant function prototype.
 * Return: Always 0
 */
int my_popenvir(info_t *myinfo)
{
	list_t *node = NULL;
	size_t y;

	for (y = 0; environ[y]; y++)
		my_appen_nod(&node, environ[y], 0);
	myinfo->env = node;
	return (0);
}
