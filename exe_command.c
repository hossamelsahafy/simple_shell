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
	int status;

	pid = fork();
	if (pid == 0)
	{
		if (execve(ts[0], ts, env) == -1)
		{
			perror("./shell");
			exit(EXIT_FAILURE);
		}
	}
	else if (pid > 0)
	{
		wait(&status);
	}
	if (WIFEXITED(status))
	{
		return (WEXITSTATUS(status));
	}
	else
	{
		perror("error");
		exit(EXIT_FAILURE);
	}
	return (0);
}
