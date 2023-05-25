#include "shell.h"

/**
 * my_hand_envs - Prints the env variables.
 * Return: empty function
 */

void my_hand_envs(void)
{
	char **nv = environ;

	while (*nv)
	{
		printf("%s\n", *nv);
		nv++;
	}
}

