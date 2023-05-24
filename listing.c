#include "headers.h"

/**
 * my_lilen - count length of linked list
 * @myh: pointe at the first node
 *
 * Return: size of list
 */
size_t my_lilen(const list_t *myh)
{
	size_t y = 0;

	while (myh)
	{
		myh = myh->next;
		y++;
	}
	return (y);
}

/**
 * my_conv_strin - give back an arrays strings of the list->str
 * @myhead: pointe at first node
 *
 * Return: array of strings
 */
char **my_conv_strin(list_t *myhead)
{
	list_t *node = myhead;
	size_t y = my_lilen(myhead), j;
	char **strs;
	char *str;

	if (!myhead || !y)
		return (NULL);
	strs = malloc(sizeof(char *) * (y + 1));
	if (!strs)
		return (NULL);
	for (y = 0; node; node = node->next, y++)
	{
		str = malloc(_strlen(node->str) + 1);
		if (!str)
		{
			for (j = 0; j < y; j++)
				free(strs[j]);
			free(strs);
			return (NULL);
		}

		str = _strcpy(str, node->str);
		strs[y] = str;
	}
	strs[y] = NULL;
	return (strs);
}


/**
 * my_listpr - display all elements de list_t linked list
 * @myh: pointer to first node
 *
 * Return: list size
 */
size_t my_listpr(const list_t *myh)
{
	size_t m = 0;

	while (myh)
	{
		_puts(my_convnum(myh->num, 10, 0));
		_putchar(':');
		_putchar(' ');
		_puts(myh->str ? myh->str : "(nil)");
		_puts("\n");
		myh = myh->next;
		m++;
	}
	return (m);
}

/**
 * my_find_node - give back nodes that string bigen with myprefix
 * @node: pointe at list myhead
 * @myprefix: match to string
 * @myc: the following character that match after myprefix
 *
 * Return: similar node or null
 */
list_t *my_find_node(list_t *node, char *myprefix, char myc)
{
	char *p = NULL;

	while (node)
	{
		p = my_strstart(node->str, myprefix);
		if (p && ((myc == -1) || (*p == myc)))
			return (node);
		node = node->next;
	}
	return (NULL);
}

/**
 * my_get_index - geting node index
 * @myhead: pointe at list myhead
 * @node: pointe at the node
 *
 * Return: index of node or -1
 */
ssize_t my_get_index(list_t *myhead, list_t *node)
{
	size_t y = 0;

	while (myhead)
	{
		if (myhead == node)
			return (y);
		myhead = myhead->next;
		y++;
	}
	return (-1);
}

