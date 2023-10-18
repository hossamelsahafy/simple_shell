#include "main.h"
/**
 * _strdup - function to act like sttrdup
 *
 * @s: parameter point to const char
 *
 * Return: will be d
*/
char *_strdup(char *s)
{
	char *d;

	if (s == NULL)
	{
		return (NULL);
	}
	d = malloc(strlen(s) + 1);
	if (d == NULL)
	{
		return (NULL);
	}
	_strcpy(d, s);
	return (d);
}
