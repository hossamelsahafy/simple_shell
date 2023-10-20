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
		write(STDOUT_FILENO, "$ ", 2);
		signal(SIGINT, handler);
		loop(env);
	}
	else
	{
		non_interactive(env);
	}
	return (0);
}
