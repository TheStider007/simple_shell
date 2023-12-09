#include "main.h"

/**
 * free2Darray - frees a 2D array of strings.
 * @array: 2D array of strings.
 * Return: void.
*/

void free2Darray(char **array)
{
	int i;

	if (!array)
		return;

	for (i = 0; array[i]; i++)
	{
		free(array[i]);
		array[i] = NULL;
	}
	free(array), array = NULL;
}

/**
 * reverse_string - reverses a string.
 * @str: string to reverse.
 * @len: length of string.
 * Return: void.
*/

void reverse_string(char *str, int len)
{
	char tmp;
	int start = 0;
	int end = len - 1;

	while (start < end)
	{
		tmp = str[start];
		str[start] = str[end];
		str[end] = tmp;
		start++;
		end--;
	}
}

/**
 * _itoa - converts an integer to a string.
 * @n: integer to convert.
 * Return: string.
*/

char *_itoa(int n)
{
	char buffer[20];
	int i = 0;

	if (n == 0)
		buffer[i++] = '0';
	else
	{
		while (n > 0)
		{
			buffer[i++] = (n % 10) + '0';
			n /= 10;
		}
	}

	buffer[i] = '\0';
	reverse_string(buffer, i);

	return (_strdup(buffer));
}

/**
 * print_error - prints an error message.
 * @name: name of program.
 * @cmd: command that failed.
 * @count: index of command.
 * Return: void.
*/

void print_error(char *name, char *cmd, int count)
{
	char *index, mssg[] = ": not found\n";

	index = _itoa(count);

	write(STDERR_FILENO, name, _strlen(name));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, index, _strlen(index));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, cmd, _strlen(cmd));
	write(STDERR_FILENO, mssg, _strlen(mssg));
	free(index);
}
