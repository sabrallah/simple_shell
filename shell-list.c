#include "headers.h"

/**
 * my_lilen - count length of linked list
 * @myh: pointe at the first node
 *
 * Return: size of list
 */
size_t my_lilen(const listing_t *myh)
{
	size_t y = 0;

	while (myh)
	{
		myh = myh->nxt;
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
char **my_conv_strin(listing_t *myhead)
{
	listing_t *node = myhead;
	size_t y = my_lilen(myhead), j;
	char **strs;
	char *str;

	if (!myhead || !y)
		return (NULL);
	strs = malloc(sizeof(char *) * (y + 1));
	if (!strs)
		return (NULL);
	for (y = 0; node; node = node->nxt, y++)
	{
		str = malloc(_strlen(node->strChar) + 1);
		if (!str)
		{
			for (j = 0; j < y; j++)
				free(strs[j]);
			free(strs);
			return (NULL);
		}

		str = _strcpy(str, node->strChar);
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
size_t my_listpr(const listing_t *myh)
{
	size_t m = 0;

	while (myh)
	{
		_puts(my_convnum(myh->numInt, 10, 0));
		_putchar(':');
		_putchar(' ');
		_puts(myh->strChar ? myh->strChar : "(nil)");
		_puts("\n");
		myh = myh->nxt;
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
listing_t *my_find_node(listing_t *node, char *myprefix, char myc)
{
	char *p = NULL;

	while (node)
	{
		p = my_strstart(node->strChar, myprefix);
		if (p && ((myc == -1) || (*p == myc)))
			return (node);
		node = node->nxt;
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
ssize_t my_get_index(listing_t *myhead, listing_t *node)
{
	size_t y = 0;

	while (myhead)
	{
		if (myhead == node)
			return (y);
		myhead = myhead->nxt;
		y++;
	}
	return (-1);
}

