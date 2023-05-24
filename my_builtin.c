#include "headers.h"

/**
 * my_exitshell - shell to exit
 * @myinfo: potential arguments contained by arguments. Use to maintain
 * constant functions prototype.
 * Return: a given exit statusInt that exit
 * (0) if myinfo.argvChar[0] != "exit"
 */
int my_exitshell(info_pass *myinfo)
{
	int yexit_check;

	if (myinfo->argvChar[1]) /* If there is an exit arguement */
	{
		yexit_check = my_strtoint(myinfo->argvChar[1]);
		if (yexit_check == -1)
		{
			myinfo->statusInt = 2;
			my_erroprint(myinfo, "Illegal number: ");
			my_printstr(myinfo->argvChar[1]);
			my_chrtostderr('\n');
			return (1);
		}
		myinfo->err_numInt = my_strtoint(myinfo->argvChar[1]);
		return (-2);
	}
	myinfo->err_numInt = -1;
	return (-2);
}

/**
 * my_chgdir - changes processing current current directory
 * @myinfo: potential arguments contained by structure. Use for maintain
 * constant functions prototype.
 * Return: Always 0
 */
int my_chgdir(info_pass *myinfo)
{
	char *y, *ydir, buffer[1024];
	int chdir_ret;

	y = getcwd(buffer, 1024);
	if (!y)
		_puts("TODO: >>getcwd failure emsg here<<\n");
	if (!myinfo->argvChar[1])
	{
		ydir = my_getenv(myinfo, "HOME=");
		if (!ydir)
			chdir_ret = /* TODO: what should this be? */
				chdir((ydir = my_getenv(myinfo, "PWD=")) ? ydir : "/");
		else
			chdir_ret = chdir(ydir);
	}
	else if (_strcmp(myinfo->argvChar[1], "-") == 0)
	{
		if (!my_getenv(myinfo, "OLDPWD="))
		{
			_puts(y);
			_putchar('\n');
			return (1);
		}
		_puts(my_getenv(myinfo, "OLDPWD=")), _putchar('\n');
		chdir_ret = /* TODO: what should this be? */
			chdir((ydir = my_getenv(myinfo, "OLDPWD=")) ? ydir : "/");
	}
	else
		chdir_ret = chdir(myinfo->argvChar[1]);
	if (chdir_ret == -1)
	{
		my_erroprint(myinfo, "can't cd to ");
		my_printstr(myinfo->argvChar[1]), my_chrtostderr('\n');
	}
	else
	{
		my_envsett(myinfo, "OLDPWD", my_getenv(myinfo, "PWD="));
		my_envsett(myinfo, "PWD", getcwd(buffer, 1024));
	}
	return (0);
}

/**
 * my_disphelp - the process changes of current directory
 * @myinfo: potential arguments contained by structure. Use too maintain
 * constant function prototype.
 * Return: Always 0
 */
int my_disphelp(info_pass *myinfo)
{
	char **yarg_array;

	yarg_array = myinfo->argvChar;
	_puts("help call works. Function not yet implemented \n");
	if (0)
		_puts(*yarg_array); /* temp att_unused workaround */
	return (0);
}
