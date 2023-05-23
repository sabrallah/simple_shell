#include "shell.h"

/**
 * tokenize - Tokenizes input into individual tokens
 * @shell: Pointer to shell_t struct containing input string and tokens array
 *
 * This function tokenizes the input string contained in the shell_t struct by
 * breaking it down into tokens using the strtok() function.The tokens are then
 * stored in an array of strings called "tokens" within the shell_t struct. The
 * function also trims any leading or trailing whitespace from the input string
 * before tokenizing it. The maximum number of tokens that can be stored in the
 * "tokens" array is defined by the constant MAX_TOKENS. The delimiter used to
 * separate the tokens is defined by the constant TOKEN_DELIMITER. The function
 * returns void.
 */
void tokenize(shell_t *shell)
{
	int i = 0;
	char *token;

	trim(shell->input);

	token = strtok(shell->input, TOKEN_DELIMITER);
	while (token != NULL && i < MAX_TOKENS - 1)
	{
		shell->tokens[i] = token;
		i++;

		token = strtok(NULL, TOKEN_DELIMITER);
	}

	shell->tokens[i] = NULL;
}
