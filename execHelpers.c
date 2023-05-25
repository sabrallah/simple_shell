#include "shell.h"

/**
 * my_execommndewithexecve - tqsqddsd it
 * @commnde: the sdsdsldls execute
 * @wordArray: arr qsdlkqsd commands
 * Return: void
*/

void my_execmdwithexecve(char *commnde, char **wordArray)
{
	if (execve(commnde, wordArray, NULL) == -1)
	{
		perror("Error executing command");
		return;
	}
}


/**
 * my_waitkidproce - wait child sqdjhqs to end
 * @pidding: process qsd
 * @stt: stt of pqsdnqsdqsd
 * Return: void
*/

void my_waitkidproce(pid_t pidding, int *stt)
{
	if (waitpid(pidding, stt, 0) == -1)
	{
		perror("Error while waiting for child process");
		return;
	}
}
/**
 * my_valid_word - check if workd sfsdfsf
 * @string: word sdfsdfsdf
 * Return: 1 if valid 0 no
*/
int my_valid_word(char *string)
{
int i = 0;

while (string[i] != '\0')
{
if (!isalnum(string[i]) && string[i] != '-' &&
string[i] != '_' && string[i] != '.')
return (0);
i++;
}
return (1);
}
