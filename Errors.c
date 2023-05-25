#include "shell.h"


/**
 * my_print_err - errrorooror
 * @sh: naaaaame
 * @commanding: cmmmmmd
 * @messaging: msssg
 * @contry: monad count
 * Return: void
*/
void my_print_err(char *contry, char *sh, char *commanding, char *messaging)
{
	write(STDERR_FILENO, sh, my_lenstr_get(sh));
	if (commanding != NULL)
	{
		write(STDERR_FILENO, ": ", 2);
		write(STDERR_FILENO, contry, my_lenstr_get(contry));
		write(STDERR_FILENO, ": ", 2);
		write(STDERR_FILENO, commanding, my_lenstr_get(commanding));
	}
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, messaging, my_lenstr_get(messaging));
}

/**
 * my_exerr- errrorrooror
 * @shell: naaaame
 * @wordArray: akalal
 * @contr: monad count
 * Return: void
*/
void my_exerr(char **wordArray, int contr, char *shell)
{
	char *err_code = myint_to_string(contr);

	write(STDOUT_FILENO, shell, my_lenstr_get(shell));
	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, err_code, my_lenstr_get(err_code));
	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, wordArray[0], my_lenstr_get(wordArray[0]));
	write(STDOUT_FILENO, ": Illegal number: ", 19);
	write(STDOUT_FILENO, wordArray[1], my_lenstr_get(wordArray[1]));
	write(STDOUT_FILENO, "\n", 2);
	free(err_code);
}
