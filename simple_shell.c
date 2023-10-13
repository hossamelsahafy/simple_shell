#include "main.h"

/**
 * main- entry function to simple shell
 *
 * Return: will  be 0
 */
int main(void)
{
	int interactive = isatty(STDIN_FILENO);
	char **env = __environ;
	
	if (interactive)
	{
		signal(SIGINT, handler);
		signal(SIGTSTP, handler);
	}
	loop(env);
	return (0);
}
