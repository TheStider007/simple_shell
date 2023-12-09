#include "main.h"

/**
 * _getenv - finds the PATH variable in the environment.
 * @var: array of environment variables.
 * Return: pointer to the PATH variable.
*/

char *_getenv(char *var)
{
	char *temp, *key, *env;
	int i;

	i = 0;
	while (environ[i])
	{
		temp = strdup(environ[i]);
		key = strtok(temp, "=");
		if (strcmp(key, var) == 0)
		{
			env = _strdup(strtok(NULL, "\n"));
			if (env && *env == '\0')
				free(env), env = NULL;
			free(temp);
			return (env);
		}
		free(temp), temp = NULL;
		i++;
	}
	return (NULL);
}