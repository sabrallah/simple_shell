#include "shell.h"

/**
 * split_string - splits a string into an wrdsN array
 * @stringing: str -> be splited
 * @sprt: delimetering
 * @wrdsN: wrdXs num in the str
 * Return: string array || NULL
*/

char **split_string(char *stringing, const char *sprt, int *wrdsN)
{
	char *copping = NULL, *wrdX = NULL, **wArray;
	int i;

	copping = malloc(sizeof(char) * my_lenstr_get(stringing) + 1);
	if (copping == NULL)
	{
		perror("Allocation Failed !");
		return (NULL);
	}
	my_copy_str(copping, stringing);

	*wrdsN = 0;
	wrdX = strtok(stringing, sprt);
	while (wrdX != NULL)
	{
		(*wrdsN)++;
		wrdX = strtok(NULL, sprt);
	}
	wArray = malloc(sizeof(char *) * (*wrdsN + 1));
	if (wArray == NULL)
	{
		perror("Allocation Failed !");
		return (NULL);
	}
	wrdX = strtok(copping, sprt);
	for (i = 0; wrdX != NULL; i++)
	{
		wArray[i] = malloc(sizeof(char) * my_lenstr_get(wrdX) + 1);
		if (wArray[i] == NULL)
		{
			perror("Allocation Failed !");
			return (NULL);
		}
		my_copy_str(wArray[i], wrdX);
		wrdX = strtok(NULL, sprt);
	}

	wArray[i] = NULL;
	free(copping);
	return (wArray);
}

