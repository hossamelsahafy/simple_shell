#include "main.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

/**
 * e_b - function to excute diffrent actions
 * based on input of strirng
 *
 * @ts: parameter point to char
 *
 * @env: parameter point to char
 *
 * Return: if code  fails return will be 1
 * otherwise 0
 */

int e_b(char **ts, char **env)
{
	int i;

	if (strcmp(ts[0], "exit") == 0)
	{
		for (i = 0; ts[i] != NULL; i++)
		{
			free(ts[i]);
		}
		free(ts);
		exit(0);
	}
	else if (strcmp(ts[0], "cd") == 0)
	{
		return (handle_cd(ts));
	}
	else if (strcmp(ts[0], "env") == 0)
	{
		return (handle_env(env));
	}
	else
	{
		perror("ERRNO");
		return (1);
	}
	return (0);
}
