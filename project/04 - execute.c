#include "main.h"

/**
 * executeCommand - executes a command.
 * @cmd: command to execute.
 * @av: array of arguments.
 * @index: index of command.
 * Return: 0 in success, 1 in failure.
 */

int executeCommand(char **cmd, char **av, int index)
{
	pid_t child_pid;
	char *path;
	int status ;

	path = _getPath(cmd[0]);
	if (!path)
	{
		print_error(av[0], cmd[0], index);
		free2Darray(cmd);
		return (127);
	}

	child_pid = fork();

	if (child_pid == 0)
	{
		if (execve(path, cmd, environ) == -1)
		{
			free2Darray(cmd);
			free(path), path = NULL;
		}
	}
	else
	{
		waitpid(child_pid, &status, 0);
		free2Darray(cmd);
		free(path), path = NULL;
	}
	return (WEXITSTATUS(status));
}
