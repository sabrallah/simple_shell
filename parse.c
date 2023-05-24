#include "shell.h"

/**
 * parse_line - function that parses a line into individual tokens
 * @line: string input to be parsed
 *
 * Return: double pointer to array of parsed tokens
 */
char **parse_line(char *line)
{
	int bufsize = BUFSIZE;
	int position = 0;
	char **tokens = malloc(bufsize * sizeof(char *));
	char *token;

	if (!tokens)
	{
		handle_error("Failed to allocate memory.");
	}

	token = strtok(line, DELIM);
	while (token != NULL)
	{
		tokens[position] = token;
		position++;

		if (position >= bufsize)
		{
			bufsize += BUFSIZE;
			tokens = realloc(tokens, bufsize * sizeof(char *));
			if (!tokens)
			{
				handle_error("Failed to allocate memory.");
			}
		}

		token = strtok(NULL, DELIM);
	}
	tokens[position] = NULL;
	return (tokens);
}

