#include "main.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

/**
 * c_b - function to compare built-in commands with
 * the input string
 *
 * @token: parameter point to char
 *
 * Return: will be 1 if match found other wise 0
*/
char c_b(char *token)
{
	const char *builtin[] = {"cd", "env", "exit", NULL};
	int i;

	for (i = 0; builtin[i] != NULL; i++)
	{
		if (strcmp(token, builtin[i]) == 0)
		{
			return (1);
		}
	}
	return (0);
}
