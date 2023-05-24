#include "headers.h"

/**
 * my_histoir - affiches the history list, each command by line, preceded
 *              what line numbers, starting at 0.
 * @myinfo: potential arguments contained by structure. for that maintain
 *        constant function prototype.
 *  Return: Always 0
 */
int my_histoir(info_t *myinfo)
{
	my_listpr(myinfo->history);
	return (0);
}

/**
 * my_delalias - string seting from alias
 * @myinfo: structur of parameters
 * @mystr: the string alias
 *
 * Return: Always 0 on success, 1 on error
 */
int my_delalias(info_t *myinfo, char *mystr)
{
	char *y, m;
	int yret;

	y = my_strfin(mystr, '=');
	if (!y)
		return (1);
	m = *y;
	*y = 0;
	yret = my_remov_node_index(&(myinfo->alias),
		my_get_index(myinfo->alias, my_find_node(myinfo->alias, mystr, -1)));
	*y = m;
	return (yret);
}

/**
 * my_newalias - string seting from alias
 * @myinfo: structures parametres
 * @mystr: the alias string
 *
 * Return: Always 0 on success, 1 on error
 */
int my_newalias(info_t *myinfo, char *mystr)
{
	char *y;

	y = my_strfin(mystr, '=');
	if (!y)
		return (1);
	if (!*++y)
		return (my_delalias(myinfo, mystr));

	my_delalias(myinfo, mystr);
	return (my_appen_nod(&(myinfo->alias), mystr, 0) == NULL);
}

/**
 * my_dispalias - alias string printed
 * @mynode: the alias mynode
 *
 * Return: Always 0 on success, 1 on error
 */
int my_dispalias(list_t *mynode)
{
	char *y = NULL, *m = NULL;

	if (mynode)
	{
		y = my_strfin(mynode->str, '=');
		for (m = mynode->str; m <= y; m++)
		_putchar(*m);
		_putchar('\'');
		_puts(y + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}


/**
 * my_builtalias - similar to alias builtin (refrence alias)
 * @myinfo: potential arguments contained by structure. Used to maintain
 *          constant function prototype.
 *  Return: Always 0
 */
int my_builtalias(info_t *myinfo)
{
	int y = 0;
	char *m = NULL;
	list_t *mynode = NULL;

	if (myinfo->argc == 1)
	{
		mynode = myinfo->alias;
		while (mynode)
		{
			my_dispalias(mynode);
			mynode = mynode->next;
		}
		return (0);
	}
	for (y = 1; myinfo->argv[y]; y++)
	{
		m = my_strfin(myinfo->argv[y], '=');
		if (m)
			my_newalias(myinfo, myinfo->argv[y]);
		else
			my_dispalias(my_find_node(myinfo->alias, myinfo->argv[y], '='));
	}

	return (0);
}
