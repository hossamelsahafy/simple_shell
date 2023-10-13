#include "main.h"
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * execute - function to execute built-in commands
 *
 * @ts: parameter that point to char
 *
 * @env: parameter that point to char
 */

void execute(char **ts, char **env)
{
	pid_t pid;
	int status;

	pid  = fork();
	if (pid == 0)
	{
		if (execve(ts[0], ts, env) == -1)
		{
			perror("./shell");
			exit(1);
		}
	}
	else if (pid > 0)
	{
		wait(&status);
	}
	else
	{
		perror("error");
		exit(1);
	}
}
