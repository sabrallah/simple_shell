#include "headers.h"

/**
 * my_bufchain - commands chain buffers.
 * @infoPtr: struct of a parameter.
 * @bufPtr: buffer address.
 * @lenPtr: len var address.
 *
 * Return: read all bytes.
 */
ssize_t my_bufchain(info_pass *infoPtr, char **bufPtr, size_t *lenPtr)
{
	ssize_t rSize = 0; /* fixing trailing white space */
	size_t len_pSize = 0; /* fixing trailing white space */

	if (!*lenPtr) /* fixing trailing white space */
	{
		free(*bufPtr);
		*bufPtr = NULL;
		signal(SIGINT, my_interrupt);
#if USE_GETLINE
		rSize = getline(bufPtr, &len_pSize, stdin);
#else
		rSize = my_lineget(infoPtr, bufPtr, &len_pSize);
#endif
		if (rSize > 0)
		{
			if ((*bufPtr)[rSize - 1] == '\n')
			{
				(*bufPtr)[rSize - 1] = '\0';
				rSize--;
			}
			infoPtr->linecount_flagInt = 1;
			my_rmcomment(*bufPtr);
			my_histori_make(infoPtr, *bufPtr, infoPtr->histcountInt++);
			{
				*lenPtr = rSize;
				infoPtr->cmd_bufChar = bufPtr;
			}
		}
	}
	return (rSize);
}

/**
 * my_input - newline getting by a line minus.
 * @infoPtr: struct of a parameter.
 *
 * Return: reading all bytes.
 */
ssize_t my_input(info_pass *infoPtr)
{
	static char *buf;
	static size_t i, j, len;
	ssize_t rSize = 0;
	char **buf_pChar = &(infoPtr->argChar), *pChar;

	_putchar(BUF_FLUSH);
	rSize = my_bufchain(infoPtr, &buf, &len); /* fixing trailing white space */
	if (rSize == -1) /* fixing trailing white space */
		return (-1); /* fixing trailing white space */
	if (len) /* fixing trailing white space */
	{	  /* fixing trailing white space */
		j = i; /* fixing trailing white space */
		pChar = buf + i; /* fixing trailing white space */
					  /* fixing trailing white space */
		my_chkchain(infoPtr, buf, &j, i, len); /* fixing trailing white space */
		while (j < len) /* fixing trailing white space */
		{			  /* fixing trailing white space */
			if (my_chain(infoPtr, buf, &j))
				break;
			j++;
		}

		i = j + 1; /* fixing trailing white space */
		if (i >= len)  /* fixing trailing white space */
		{			  /* fixing trailing white space */
			i = len = 0;
			infoPtr->cmd_buf_typeInt = CMD_NORM;
		}

		*buf_pChar = pChar;
		return (_strlen(pChar)); /* fixing trailing white space */
	}				  /* fixing trailing white space */

	*buf_pChar = buf;
	return (rSize); /* fixing trailing white space */
} /* fixing trailing white space */

/**
 * my_bufread - buffer to be reading.
 * @infoPtr: struct of an parameter.
 * @bufPtr: bufferPtr.
 * @iPtr: rSize.
 *
 * Return: r.
 */
ssize_t my_bufread(info_pass *infoPtr, char *bufPtr, size_t *iPtr)
{
	ssize_t rSize = 0;

	if (*iPtr)
		return (0);
	rSize = read(infoPtr->readfdInt, bufPtr, READ_BUF_SIZE);
	if (rSize >= 0)
		*iPtr = rSize;
	return (rSize);
}

/**
 * my_lineget - Next line to be getting an input from STDIN.
 * @infoPtr: struct of an parameter.
 * @ptrChar: pointer address => buffer, NULL || preallocated.
 * @lengthPtr: preallocated size buffer ptr if not NULL.
 *
 * Return: the final s.
 */
int my_lineget(info_pass *infoPtr, char **ptrChar, size_t *lengthPtr)
{
	static char buf[READ_BUF_SIZE];
	static size_t i, len;
	size_t kS;
	ssize_t rR = 0, sS = 0;
	char *pTr = NULL, *new_ptr = NULL, *cPtr;

	pTr = *ptrChar;
	if (pTr && lengthPtr)
		sS = *lengthPtr;
	if (i == len)
		i = len = 0;

	rR = my_bufread(infoPtr, buf, &len);
	if (rR == -1 || (rR == 0 && len == 0))
		return (-1);

	cPtr = my_strfin(buf + i, '\n');
	kS = cPtr ? 1 + (unsigned int)(cPtr - buf) : len;
	new_ptr = my_ralloc(pTr, sS, sS ? sS + kS : kS + 1);
	if (!new_ptr) /* MALLOC not secss */
		return (pTr ? (free(pTr), -1) : -1);

	if (sS)
		my_strconc(new_ptr, buf + i, kS - i);
	else
		my_strlimit(new_ptr, buf + i, kS - i + 1);

	sS += kS - i;
	i = kS;
	pTr = new_ptr;

	if (lengthPtr)
		*lengthPtr = sS;
	*ptrChar = pTr;
	return (sS);
}

/**
 * my_interrupt - ctrl-C to be preallocated.
 * @sig_num: number that signal.
 *
 * Return: void (no parameter function).
 */
void my_interrupt(__attribute__((unused))int sig_num)
{
	_puts("\n");
	_puts("$ ");
	_putchar(BUF_FLUSH);
}


