#include "main.h"
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>

/**
 * handler  - function to handel ctrl c & z
 *
 * @sig: parameter to identify int
 */
void handler(int sig)
{
	if (sig == SIGINT)
	{
		signal(sig, SIG_IGN);
	}
	else if (sig == SIGTSTP)
	{
		signal(sig, SIG_IGN);
		write(STDOUT_FILENO, "\n$ ", 3);
	}
}
