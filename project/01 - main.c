#include "main.h"

/**
 * main - program entry point.
 * @argc: number of arguments.
 * @argv: array of arguments.
 * Return: 0 in success, 1 in failure.
 */

int main(int argc, char **argv)
{
	char *line, **cmd;
	int index, status = 0;

	(void) argc;
	line = NULL, cmd = NULL;
	index = 0;
	while (1)
	{
		line = read_line();

		if (line == NULL)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			return (status);
		}
		index++;
		cmd = tokenizeString(line);
		if (!cmd)
			continue;
		status = executeCommand(cmd, argv, index);
	}
	return (0);
}
