#include "main.h"

/**
 * non_interactive - function to handel non interactive mode in simple  shell
 *
 * @env: parametr point to char
 *
 * Return: will be 0
*/
int non_interactive(char **env)
{
	char *l = NULL;
	size_t len = 0;
	ssize_t rs = 0;
	char **ts;

	while ((rs = getline(&l, &len, stdin)) != -1)
	{
		if (rs > 1)
		{
			ts = p_l(l);
			if (c_b(ts[0]) == 1)
			{
				e_b(ts, env);
			}
			else if (access(ts[0], F_OK) == 0)
			{
				exe_command(ts, env);
			}
			else  if (access(ts[0], F_OK) == -1)
			{
				perror("command");
				exit(1);
			}
			else
			{
				write(1, l, _strlen(l));
				write(1, "\n", 1);
			}
			free(ts);
		}
		free(l);
		l = NULL;
		len = 0;
	}
	return (0);
}
