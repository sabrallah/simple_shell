#include "shell.h"

/**
 * my_cd_comd - han cd com
 * @wordArrat: to ar of wor
 * Return: void
*/

void my_cd_comd(char **wordArrat)
{
	char *drctI = NULL, *pwdO, *pwdC;

	drctI = my_getdir(wordArrat[1]);
	if (drctI == NULL)
	{
		my_error("the directory is not found");
		return;
	}
	pwdO = my_handlecwd();
	if (pwdO == NULL)
		return;
	if (my_env_set("pwdO", pwdO, 1) < 0)
	{
		free(pwdO);
		return;
	}
	free(pwdO);
	my_swit_currdir(drctI);
	pwdC = my_handlecwd();
	if (pwdC == NULL)
		return;
	if (my_env_set("PWD", pwdC, 1) < 0)
	{
		free(pwdC);
		return;
	}
	free(pwdC);
}

