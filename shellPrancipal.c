#include "shell.h"

/**
 * my_handle_sign - redding of signaling
 * @sigging: signaling
 * Return: emty function
 */
void my_handle_sign(int sigging)
{
	(void)sigging;
	write(STDOUT_FILENO, "\n$ ", 4);
}


/**
 * main - starting point of shell.
 *@argumnetC: argumnetC num
 * @argumnetV: args
 * Return: exiting code.
 */

int main(int argumnetC, char **argumnetV)
{
	char *promtH = NULL;
	int codeIn = 0, counting = 0;
	(void)argumnetC;

	 signal(SIGINT, my_handle_sign);

	while (isatty(STDIN_FILENO))
	{
		counting++;
		printf("$ ");
		promtH = my_input_read();
		if (promtH == NULL)
		{
			printf("\n");
			return (-1);
		}
		codeIn = my_exec_cmd(promtH, argumnetV[0], counting);
		free(promtH);
		promtH = NULL;
	}

	while ((promtH = my_input_read()) != NULL)
	{
		counting++;
		codeIn = my_exec_cmd(promtH, argumnetV[0], counting);
		if (promtH != NULL)
		free(promtH);
	}

	promtH = NULL;
	return (codeIn);
}

