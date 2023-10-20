#include "main.h"

/**
 * s_d - function to deal with spaces
 *
 * @l: parameter that point to char
 *
 * @env: parameter that point to char
 *
 * Return: if it fails
 */

void s_d(char *l, char **env)
{
	char **ts = NULL;
	char *tmp = l;

	while (*tmp == ' ' || *tmp == '\t' || *tmp == '\n')
	{
		tmp++;
	}
	if (*tmp == '\0')
	{
		return;
	}
	ts = p_l(l);
	if (ts[0] == NULL)
	{
		free(ts);
		return;
	}
	if (c_b(ts[0]) == 1)
	{
		e_b(ts, env);
	}
	else
	{
		execute(ts, env);
	}
	free(ts);
}
