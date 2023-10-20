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
	Shell shell;

	shell.alias_c = 0;

	if (strcmp(ts[0], "exit") == 0)
	{
		exit_handler(ts);
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
	else if (strcmp(ts[0], "alias") == 0)
	{
		alias_handler(&shell, ts);
	}
	else
	{
		perror("ERRNO");
		return (1);
	}
	return (0);
}
