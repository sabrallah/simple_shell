#include "headers.h"

/**
 * my_history_get - geting the files history
 * @myinfo: structure parametre
 *
 * Return: file history allocated string contained
 */

char *my_history_get(info_pass *myinfo)
{
	char *buf, *mydir;

	mydir = my_getenv(myinfo, "HOME=");
	if (!mydir)
		return (NULL);
	buf = malloc(sizeof(char) * (_strlen(mydir) + _strlen(HIST_FILE) + 2));
	if (!buf)
		return (NULL);
	buf[0] = 0;
	_strcpy(buf, mydir);
	_strcat(buf, "/");
	_strcat(buf, HIST_FILE);
	return (buf);
}

/**
 * my_writhisto - make a file, or extend an a existing file
 * @myinfo: structure of parametre
 *
 * Return: 1 on success, else -1
 */
int my_writhisto(info_pass *myinfo)
{
	ssize_t fd;
	char *filename = my_history_get(myinfo);
	listing_t *node = NULL;

	if (!filename)
		return (-1);

	fd = open(filename, O_CREAT | O_TRUNC | O_RDWR, 0644);
	free(filename);
	if (fd == -1)
		return (-1);
	for (node = myinfo->historyList; node; node = node->nxt)
	{
		my_strtofd(node->strChar, fd);
		my_chrtofd('\n', fd);
	}
	my_chrtofd(BUF_FLUSH, fd);
	close(fd);
	return (1);
}

/**
 * my_histread - extract history from file
 * @myinfo: the structure parametre
 *
 * Return: histcounting on right, 0 otherwise
 */
int my_histread(info_pass *myinfo)
{
	int m, last = 0, mylinecount = 0;
	ssize_t fd, rdlen, fsize = 0;
	struct stat st;
	char *buf = NULL, *filename = my_history_get(myinfo);

	if (!filename)
		return (0);

	fd = open(filename, O_RDONLY);
	free(filename);
	if (fd == -1)
		return (0);
	if (!fstat(fd, &st))
		fsize = st.st_size;
	if (fsize < 2)
		return (0);
	buf = malloc(sizeof(char) * (fsize + 1));
	if (!buf)
		return (0);
	rdlen = read(fd, buf, fsize);
	buf[fsize] = 0;
	if (rdlen <= 0)
		return (free(buf), 0);
	close(fd);
	for (m = 0; m < fsize; m++)
		if (buf[m] == '\n')
		{
			buf[m] = 0;
			my_histori_make(myinfo, buf + last, mylinecount++);
			last = m + 1;
		}
	if (last != m)
		my_histori_make(myinfo, buf + last, mylinecount++);
	free(buf);
	myinfo->histcountInt = mylinecount;
	while (myinfo->histcountInt-- >= HIST_MAX)
		my_remov_node_index(&(myinfo->historyList), 0);
	my_histor_renum(myinfo);
	return (myinfo->histcountInt);
}

/**
 * my_histori_make - type entry to an linked list history
 * @myinfo: potential arguments contained by structure. Used to maintain
 * @bufPtr: bufPtr
 * @my_linecount: the history mylinecount, histcount
 *
 * Return: Always 0
 */
int my_histori_make(info_pass *myinfo, char *bufPtr, int my_linecount)
{
	listing_t *node = NULL;

	if (myinfo->historyList)
		node = myinfo->historyList;
	my_appen_nod(&node, bufPtr, my_linecount);

	if (!myinfo->historyList)
		myinfo->historyList = node;
	return (0);
}

/**
 * my_histor_renum - addnumber to linked list history after changes
 * @infoPtr: potential arguments contained by structure. Used to maintain
 *
 * Return: the nouvelle histcount
 */
int my_histor_renum(info_pass *infoPtr)
{
	listing_t *node = infoPtr->historyList;
	int m = 0;

	while (node)
	{
		node->numInt = m++;
		node = node->nxt;
	}
	return (infoPtr->histcountInt = m);
}

