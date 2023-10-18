#include "main.h"

/**
 * path_handeler - function to excute command
 *
 * @ts: parameter that point to char
 *
 * @dir: parameter that point to char
 *
 * @env: parameter that point to char
 *
 * Return: will be 1 if command excuted
 * -1 if command didn't excute
*/
char path_handeler(char **ts, char *dir, char **env)
{
	int status;
	pid_t pid = -1;
	char *p;

	p = malloc(_strlen(dir) + _strlen(ts[0]) + 2);
	if (p == NULL)
	{
		perror("malloc");
		exit(1);
	}
	_strcpy(p, dir);
	_strcat(p, "/");
	_strcat(p, ts[0]);
	if (access(p, X_OK) == 0)
	{
		pid = fork();
		if (pid == 0)
		{
			if (execve(p, ts, env) == -1)
			{
				perror("path");
				free(p);
				return (-1);
			}
		}
		else if (pid > 0)
		{
			wait(&status);
			free(p);
			return (1);
		}
		else
		{
			perror("error");
			free(p);
			exit(1);
		}
	}
	free(p);
	return (pid == 0 ? 1 : -1);
}
