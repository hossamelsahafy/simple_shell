#include "main.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

/**
 * p_l - function to take a string as an argument and
 * returns an array of strings sparatedd by space or new line
 *
 * @s: parameter point to char
 *
 * Return: will be ts
*/
char **p_l(char *s)
{
	char **ts;
	char *token;
	int i = 0;

	ts = malloc(sizeof(char *) * 32);
	token = strtok(s, " \n");
	while (token != NULL)
	{
		ts[i] = token;
		i++;
		token = strtok(NULL, " \n");
	}
	ts[i] = NULL;
	return (ts);
}
