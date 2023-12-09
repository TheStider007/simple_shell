#include "main.h"

/**
 * _getPath - finds the PATH variable in the environment.
 * @command: array of environment variables.
 * Return: pointer to the PATH variable.
*/

char *_getPath(char *command)
{
	char *path_env, *path, *path_command;
	int i;
	struct stat st;

	i = 0;
	while (command[i])
	{
		if (command[i] == '/')
		{
			if (stat(command, &st) == 0)
				return (_strdup(command));
			return (NULL);
		}
		i++;
	}
	path_env = _getenv("PATH");
	if (!path_env)
		return (NULL);
	
	path = strtok(path_env, ":");
	while (path)
	{
		path_command = malloc(sizeof(char) * (_strlen(path) + _strlen(command) + 2));
		if (path_command)
		{
			strcpy(path_command, path);
			strcat(path_command, "/");
			strcat(path_command, command);
			if (stat(path_command, &st) == 0)
			{
				free(path_env);
				return (path_command);
			}
			free(path_command), path_command = NULL;
			path = strtok(NULL, ":");
		}
	}
	free(path_env);
	return (NULL);
}