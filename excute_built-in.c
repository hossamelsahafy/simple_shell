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
	int l_exit_s = 0;
	int status = l_exit_s;

	if (strcmp(ts[0], "exit") == 0)
	{
		if (ts[1] != NULL)
		{
			status = _atoi(ts[1]);
		}
		for (i = 0; ts[i] != NULL; i++)
		{
			free(ts[i]);
		}
		free(ts);
		exit(status);
	}
	else if (strcmp(ts[0], "cd") == 0)
	{
		return (handle_cd(ts));
	}
	else if (strcmp(ts[0], "env") == 0)
	{
		return (handle_env(env));
	}
	else if (strcmp(ts[0], "pwd") == 0)
	{
		pwd_handler();
		return (0);
	}
	else
	{
		perror("ERRNO");
		return (1);
	}
	return (0);
}
