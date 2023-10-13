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
	if (sig == SIGINT || sig == SIGTSTP)
	{
		signal(sig, SIG_IGN);
		write(STDOUT_FILENO, "\ncisfun$", 7);
	}
}
