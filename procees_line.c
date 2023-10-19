#include "main.h"

/**
 * pro_l - function to manage none inter active mode
 *
 * @l: parameter that point to char
 *
 * @env: parameter that point to char
 *
 * Return: if it fails
 */

void pro_l(char *l, char **env)
{
	char **ts;

	ts = p_l(l);
	if (ts == NULL)
	{
		return;
	}
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
