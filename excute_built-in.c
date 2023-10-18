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
	int i, j;
	const char *env_v;
	size_t env_v_l;

	if (strcmp(ts[0], "exit") == 0)
	{
		for (j = 0; ts[j] != NULL; j++)
			free(ts[j]);
		free(ts);
		exit(0);
	}
	else if (strcmp(ts[0], "cd") == 0)
	{
		if (ts[1] == NULL)
		{
			perror("ERRNO");
			return (1);
		}
		else
		{
			if (chdir(ts[1]) != 0)
			{
				perror("cd");
				return (1);
			}
		}
	}
	else if (strcmp(ts[0], "env") == 0)
	{
		if (env == NULL)
		{
			perror("env");
			return (1);
		}
		for (i = 0; env[i] != NULL; i++)
		{
			env_v = env[i];
			env_v_l = _strlen(env_v);
			write(1, env_v, env_v_l);
			write(1, "\n", 1);
		}
	}
	else
	{
		perror("ERRNO");
		return (1);
	}
	return (0);
}
