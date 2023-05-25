#include "shell.h"

/**
 * my_handle_cmd - red off env, setting, unsseting.
 * @wordArr: comand provided.
 * @sh_name: titeling.
 * @cnt: cmonad counting.
 * @n: random name.
 * @uInput: user input spacce
 * Return: 1 in case cmd is found || zero.
*/

int my_handle_cmd(char **wordArr, char *uInput,
char *sh_name, int cnt, int n)
{
	char *commnd = wordArr[0];
	int hndCmd = 0;
	(void)sh_name, (void)cnt, (void)n, (void)uInput;

	if (my_cmp_str(commnd, "env") == 0)
	{
		my_hand_envs();
		hndCmd = 1;
	}
	else if (my_cmp_str(commnd, "setenv") == 0)
	{
		if (wordArr[1] && wordArr[2])
			my_env_set(wordArr[1], wordArr[2], 1);
		else
			perror("Usage: setenv VARIABLE VALUE\n");
		hndCmd = 1;
	}
	else if (my_cmp_str(commnd, "unsetenv") == 0)
	{
		if (wordArr[1])
			my_unsetenvs(wordArr[1]);
		else
			perror("Usage: unsetenv VARIABLE\n");
		hndCmd = 1;
	}
	else if (my_cmp_str(commnd, "cd") == 0)
	{
		my_cd_comd(wordArr);
		hndCmd = 1;
	}
	return (hndCmd);
}

