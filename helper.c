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

