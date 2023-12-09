#include "main.h"
/**
 * _strlen - returns the length of a string
 * @str: string to check length
 * Return: length of string
 */

int _strlen(char *str)
{
	char *s = str;

	while (*s != '\0')
	{
		s++;
	}
	return (s - str);
}

/**
 * _strdup - returns a pointer to a newly allocated space in memory
 * @str: string to copy
 * Return: pointer to new string
 */

char *_strdup(char *str)
{
	char *s;
	int i, len = 0;

	if (str == NULL)
		return (NULL);
	while (str[len] != '\0')
		len++;
	s = malloc(sizeof(char) * (len + 1));
	if (s == NULL)
		return (NULL);
	for (i = 0; i < len; i++)
		s[i] = str[i];
	s[i] = '\0';
	return (s);
}
