#include "main.h"

/**
 * exe_command - function to excute command
 *
 * @ts: parameter that point to char
 *
 * @env: parameter that point to char
 *
 * Return: will be exit_status
*/
int exe_command(char **ts, char **env)
{
	pid_t pid;
	int exit_status;
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
		exit_status = WEXITSTATUS(status);
	}
	else
	{
		perror("error");
		exit(1);
	}
	return (exit_status);
}
