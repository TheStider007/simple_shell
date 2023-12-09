#include "main.h"
/**
 * read_line -  reads a line from stdin.
 * Return: the input string in success
 * otherwise return NULL.
 */

char *read_line(void)
{
	char *userInput;
	size_t inputLength;

	userInput = NULL;
	inputLength = 0;
	/* Display "$ " if stdout is a terminal (interactive mode) */
	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, PROMPT, 2);

	/* Retrieve input from stdin */
	if (getline(&userInput, &inputLength, stdin) == -1)
	{
		/* If getline fails due to "EOF condition" (user types Ctrl+D) */
		free(userInput);
		return (NULL);
	}

	/* Return the line containing the input */
	return (userInput);
}
