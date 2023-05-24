#include "headers.h"

/**
 * my_histoir - affiches the historyList list, each command by line, preceded
 *              what line numbers, starting at 0.
 * @myinfo: potential arguments contained by structure. for that maintain
 *        constant function prototype.
 *  Return: Always 0
 */
int my_histoir(info_pass *myinfo)
{
	my_listpr(myinfo->historyList);
	return (0);
}

/**
 * my_delalias - string seting from aliasList
 * @myinfo: structur of parameters
 * @mystr: the string aliasList
 *
 * Return: Always 0 on success, 1 on error
 */
int my_delalias(info_pass *myinfo, char *mystr)
{
	char *y, m;
	int yret;

	y = my_strfin(mystr, '=');
	if (!y)
		return (1);
	m = *y;
	*y = 0;
	yret = my_remov_node_index(&(myinfo->aliasList),
		my_get_index(myinfo->aliasList, my_find_node(myinfo->aliasList, mystr, -1)));
	*y = m;
	return (yret);
}

/**
 * my_newalias - string seting from aliasList
 * @myinfo: structures parametres
 * @mystr: the aliasList string
 *
 * Return: Always 0 on success, 1 on error
 */
int my_newalias(info_pass *myinfo, char *mystr)
{
	char *y;

	y = my_strfin(mystr, '=');
	if (!y)
		return (1);
	if (!*++y)
		return (my_delalias(myinfo, mystr));

	my_delalias(myinfo, mystr);
	return (my_appen_nod(&(myinfo->aliasList), mystr, 0) == NULL);
}

/**
 * my_dispalias - aliasList string printed
 * @mynode: the aliasList mynode
 *
 * Return: Always 0 on success, 1 on error
 */
int my_dispalias(listing_t *mynode)
{
	char *y = NULL, *m = NULL;

	if (mynode)
	{
		y = my_strfin(mynode->strChar, '=');
		for (m = mynode->strChar; m <= y; m++)
		_putchar(*m);
		_putchar('\'');
		_puts(y + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}

/**
 * my_builtalias - similar to aliasList builtin (refrence aliasList)
 * @myinfo: potential arguments contained by structure. Used to maintain
 *          constant function prototype.
 *  Return: Always 0
 */
int my_builtalias(info_pass *myinfo)
{
	int y = 0;
	char *m = NULL;
	listing_t *mynode = NULL;

	if (myinfo->argcInt == 1)
	{
		mynode = myinfo->aliasList;
		while (mynode)
		{
			my_dispalias(mynode);
			mynode = mynode->nxt;
		}
		return (0);
	}
	for (y = 1; myinfo->argvChar[y]; y++)
	{
		m = my_strfin(myinfo->argvChar[y], '=');
		if (m)
			my_newalias(myinfo, myinfo->argvChar[y]);
		else
			my_dispalias(my_find_node(myinfo->aliasList, myinfo->argvChar[y], '='));
	}

	return (0);
}
