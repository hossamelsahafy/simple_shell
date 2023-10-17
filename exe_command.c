#include "main.h"

/**
 * exe_command - function to excute command
 *
 * @ts: parameter that point to char
 *
 * @env: parameter that point to char
*/
void exe_command(char **ts, char **env)
{
	pid_t pid;
	int status;

	pid = fork();
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
