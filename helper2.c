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
/**
 * _atoi - function to convert string into integer
 *
 * @s: parameter point to char array
 *
 * Return: result of multiplying sign & result
 */

int _atoi(char *s)
{
	int sign;
	unsigned int result;
	int i;

	sign = 1;
	result = 0;
	i = 0;

	while (s[i] != '\0')
	{
		if (s[i] == '-')
			sign *= -1;
		if (s[i] >= '0' && s[i] <= '9')
			result = result * 10 + s[i] - '0';
		if (result != 0 && !(s[i] >= '0' && s[i] <= '9'))
			break;
		i++;
	}
	return (result * sign);

}
/**
 * int_to_str - function to convert int to str
 *
 * @n: parameter that point to int
 *
 * @str:  parameter that point to char
 *
 * Return: if n == 0 it will return
*/
void int_to_str(int n, char *str)
{
	int i = 0, r, s = 0, e;
	char tmp;
	int negative = 0;

	if (n == 0)
	{
		str[i++] = '\0';
		str[i] = '\0';
		return;
	}
	if (n < 0)
	{
		negative = 1;
		n = -n;
	}
	while (n != 0)
	{
		r = n % 10;
		str[i++] = r + '0';
		n = n / 10;
	}
	if (negative)
	{
		str[i++] = '-';
	}
	str[i] = '\0';
	e = i - 1;
	while (s < e)
	{
		tmp = str[s];
		str[s] = str[e];
		str[e] = tmp;
		s++;
		e--;
	}
}
