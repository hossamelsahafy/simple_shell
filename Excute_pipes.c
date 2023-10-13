#include "main.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <error.h>

#define MAX_C 10
#define MAX_A 10

void execute_pipes(char *cmd[MAX_C][MAX_A], int p)
{
    int status;
    int (*pipes)[2] = malloc((p - 1) * sizeof(int[2]));
    int i, j;
    pid_t pid;

    for (i = 0; i < p - 1; i++)
    {
        if(pipe(pipes[i]) == -1)
        {
            perror("pipe");
            exit(1);
        }
    }
    for (i = 0; i < p; i++)
    {
        pid = fork();
        if (pid == -1)
        {
            perror("fork");
            exit(1);
        }
        else if (pid == 0)
        {
            if (i > 0)
            {
                dup2(pipes[i - 1][0], STDIN_FILENO);
                close(pipes[i - 1][0]);
                close(pipes[i - 1][1]);
            }
            if (i < p - 1)
            {
                dup2(pipes[i][1], STDOUT_FILENO);
                close(pipes[i][0]);
                close(pipes[i][1]);
            }
            if (execvp(cmd[i][0], cmd[i]) == -1)
            {
                perror("execvp");
                exit(1);
            }
        }
        else
        {
            if (i > 0)
            {
                close(pipes[i - 1][0]);
                close(pipes[i - 1][1]);
            }
        }
    }
    for (i = 0; i < p - 1; i++)
    {
        close(pipes[i][0]);
        close(pipes[i][1]);
    }
    for (i = 0; i < p; i++)
    {
        wait(&status);
    }

    free(pipes);

    for (i = 0; i < p; i++)
    {
        for (j = 0; cmd[i][j] != NULL; j++)
        {
            free(cmd[i][j]);
        }
    }
}
