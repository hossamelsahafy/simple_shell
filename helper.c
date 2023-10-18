#include "main.h"
/**
 * _strlen - function to print numbers of letters
 *
 * @s: parameter point to integer
 *
 * *: dereference the pointer and access the value that points to
 *
 * Return: always len
 */
int _strlen(const char *s)
{
	int len;

	len = 0;
	while (*s != '\0')
	{
		len++;
		s++;
	}
	return (len);
}

/**
 * _strcpy - function to copy string
 *
 * @dest: parameter point to the buffer
 *
 * @src: parameter point to the string that will be copied
 *
 * Return: itt will return to dest
 */
char *_strcpy(char *dest, char *src)
{
	char *p = dest;

	while (*src != '\0')
	{
		*p++ = *src++;
	}
	*p = '\0';

	return (dest);
}

/**
 *_strcat - function to concatenates two strings
 *
 * @dest: parameter point to char
 *
 * @src: parameter point to char
 *
 *  Return: always dest
 */
char *_strcat(char *dest, char *src)
{
	int i, j;

	i = 0;
	while (dest[i] != '\0')
	{
		i++;
	}
	j = 0;
	while (src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

/**
 * _strchr - function to  locate a character in a string
 *
 * @s: parameter point to char
 *
 * @c: parameter poin to char
 *
 * Return: if s == c it will return the pointer s
 * else it will return null
 */
char *_strchr(char *s, char c)
{
	while (*s != '\0' && *s != c)
	{
		s++;
	}
	if (*s == c)
	{
		return (s);
	}
	else
	{
		return (NULL);
	}
}

/**
 * _strcmp - function to compare two strings
 *
 * @s1: parameter to point to char
 *
 * @s2: parameter point to char
 *
 * Return: will be s1[i] - s2[i]
 */
int _strcmp(char *s1, char *s2)
{
	int i = 0;

	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] == s2[i])
		{
			i++;
			continue;
		}
		if (s1[i] >= 'A' && s1[i] <= 'Z')
		{
			if (s1[i] + 32 == s2[i])
			{
				i++;
				continue;
			}
		}
		if (s2[i] >= 'A' && s2[i] <= 'Z')
		{
			if (s2[i] + 32 == s1[i])
			{
				i++;
				continue;
			}
		}
		return (s1[i] - s2[i]);
	}
	return (s1[i] - s2[i]);
}
