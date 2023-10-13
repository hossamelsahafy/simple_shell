#include "main.h"
#include <stdio.h>
#include <errno.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define MAX_C 10
#define MAX_A 10
#define MAX_P 8

void pipes(char *i, char *cmd[MAX_C][MAX_A], int p)
{
	int cmd_n = 0;
	int arg_n;
	char *token;
	char *arg;
	int pipe_n = 0;
	int _pipe[MAX_P][2];
	pid_t pid;
	int status;

	token = strtok(i, "|");
	while (token != NULL)
	{
		arg_n = 0;
		arg = strtok(token, " ");
		while (arg != NULL)
		{
			cmd[cmd_n] [arg_n] = arg;
			arg_n++;
			arg = strtok(NULL, " ");
		}
		cmd[cmd_n][arg_n] = NULL;
		cmd_n++;
		token = strtok(NULL, "|");
		if (cmd_n < p)
		{
			if (pipe(_pipe[cmd_n - 1]) == -1)
			{
				perror("pipe");
				exit(1);
			}
		}
	}
	for (pipe_n = 0; pipe_n < p; pipe_n++)
	{
		pid = fork();
		if (pid == -1)
		{
			perror("fork");
			exit(1);
		}
		else if (pid == 0)
		{
			if (pipe_n > 0)
			{
				dup2(_pipe[pipe_n - 1][0], 0);
				close(_pipe[pipe_n - 1][0]);
				close(_pipe[pipe_n - 1][1]);
			}
			if (pipe_n < p - 1)
			{
				dup2(_pipe[pipe_n + 1][1], 1);
				close(_pipe[pipe_n][0]);
				close(_pipe[pipe_n][1]);
			}
			execvp(cmd[pipe_n][0], cmd[pipe_n]);
			perror("execvp");
			exit(1);
		}
		else
		{
			close(_pipe[pipe_n][1]);
			waitpid(pid, &status, 0);
		}
	}
}

