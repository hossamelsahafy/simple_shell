#include "main.h"

/**
 * non_interactive - function to handel non interactive mode in simple  shell
 *
 * @l: parameter that point to char
 *
 * @env: parametr point to char
 *
 * Return: will be 0
*/
int non_interactive(char *l, char **env)
{
	int interactive = isatty(STDIN_FILENO);
	size_t len = 0;
	ssize_t rs = 0;

	if (interactive)
	{
		write(STDOUT_FILENO, "cisfun$ ", 8);
		signal(SIGINT, handler);
		signal(SIGTSTP, handler);
	}
	else
	{
		while ((rs = getline(&l, &len, stdin)) != 1)
		{
			loop(env);
			free(l);
			l = NULL;
			len = 0;
		}
		free(l);
		exit(0);
	}
	while (1)
	{
		rs = getline(&l, &len, stdin);
		if (rs == -1)
		{
			perror("write");
			write(STDOUT_FILENO, "\n", 1);
			free(l);
			break;
		}
		loop(env);
		free(l);
		l = NULL;
		len = 0;
		if (interactive)
			write(STDOUT_FILENO, "cisfun$ ", 8);
	}
	return (0);
}
