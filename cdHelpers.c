#include "shell.h"

/**
 * my_envvars - an environment variable to print.
 * @envChar: environment variable the name.
 * @envPtr: variables array envirenment to print.
 *
 * Return: variable envirenement value.
 */
char *my_envvars(const char *envChar, char **envPtr)
{
	char **envPointer;

	for (envPointer = envPtr; *envPointer != NULL; envPointer++)
	{
		if (strncmp(envChar, *envPointer, my_lenstr_get(envChar)) == 0
				&& (*envPointer)[my_lenstr_get(envChar)] == '=')
		{
			return (*envPointer + my_lenstr_get(envChar) + 1);
		}
	}
	return (NULL);
}

/**
 * my_error - message error print.
 * @message: message to print error.
 */
void my_error(const char *message)
{
	printf("cd: %s\n", message);
}

/**
 * my_getdir - the directory point get change to.
 * @pathing: path passed to initials cd.
 *
 * Return: the directory point get change to.
 */
char *my_getdir(const char *pathing)
{
	if (pathing == NULL)
		return (my_envvars("HOME", environ));
	else if (my_cmp_str(pathing, "-") == 0)
		return (my_envvars("the_old_pwd", environ));
	else
		return ((char *)pathing);
}

/**
 * my_handlecwd - working directory Pointe to.
 *
 * Return: directory pointer cureent working.
 */
char *my_handlecwd()
{
	char *cwdPoiter;

	cwdPoiter = getcwd(NULL, 0);
	if (cwdPoiter == NULL)
		perror("cd");
	return (cwdPoiter);
}

/**
 * my_swit_currdir - Changes the directory current working.
 * @drtrPointer: The directory poit to change to.
 */
void my_swit_currdir(const char *drtrPointer)
{
	if (chdir(drtrPointer) < 0)
		perror("cd");
}
