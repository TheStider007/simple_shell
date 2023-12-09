#include "main.h"

/**
 * countTokens - counts the number of tokens in a string.
 * @inputString: string to count tokens from.
 * Return: number of tokens.
 */

int countTokens(char *inputString)
{
	char *temp, *token;
	int tokenCount;

	if (!inputString)
	{
		return (0);
	}

	temp = _strdup(inputString);
	if (!temp)
	{
		return (0);
	}

	tokenCount = 0;
	token = strtok(temp, " \t\n");

	if (!token) /* If there are no tokens, return 0 */
	{
		free(temp);
		return (0);
	}

	while (token)
	{
		tokenCount++;
		token = strtok(NULL, " \t\n");
	}

	free(temp);

	return (tokenCount);
}

/**
 * tokenizeString - tokenizes a string.
 * @inputString: string to tokenize.
 * Return: pointer to an array of tokens.
 */

char **tokenizeString(char *inputString)
{
	char *token, **tokenArray;
	int tokenCount, i;

	tokenCount = countTokens(inputString);
	if (tokenCount == 0)
		return (free(inputString), NULL);

	tokenArray = malloc(sizeof(char *) * (tokenCount + 1));
	if (!tokenArray)
		return (free(inputString), NULL);

	token = strtok(inputString, " \t\n");
	i = 0;
	while (i < tokenCount)
	{
		tokenArray[i] = _strdup(token);
		if (!tokenArray[i])
			return (freeResources(tokenArray, i, inputString), NULL);
		token = strtok(NULL, " \t\n");
		i++;
	}
	tokenArray[tokenCount] = NULL;
	free(inputString);
	return (tokenArray);
}

/**
 * freeResources - frees resources.
 * @tokenArray: array of tokens.
 * @i: index.
 * @inputString: string to free.
 * Return: void.
 */

void freeResources(char **tokenArray, int i, char *inputString)
{
	while (i--)
		free(tokenArray[i]);
	free(tokenArray);
	free(inputString);
}
