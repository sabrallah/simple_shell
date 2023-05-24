#include "shell.h"

/**
 * display_prompt - Prints the shell prompt.
 *
 * This function prints the value of the PROMPT constant, which should
 * contain a string that represents the shell prompt.
 */
void display_prompt(void)
{
	printf("%s", PROMPT);
}

