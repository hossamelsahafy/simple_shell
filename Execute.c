#include "main.h"
/**
 * execute - function to excute commands
 *
 * @ts: parameter that point to char
 *
 * @env: parameter that point to char
 */
void execute(char **ts, char **env)
{
	int is_p = 0;
	char *pth;
	char *c_pth;
	char *dir;

	pth = getenv("PATH");
	c_pth = _strdup(pth);
	dir  = strtok(c_pth, ":");
	if (_strchr(ts[0], '/') != NULL)
	{
		is_p = 1;
	}
	if (is_p != 0)
	{
		exe_command(ts, env);
	}
	else
	{
		while (dir != NULL)
		{
			if (path_handeler(ts, dir, env) == 1)
			{
				break;
			}
			dir = strtok(NULL, ":");
		}
		if (dir == NULL)
		{
			perror("command");
		}
	}
	free(c_pth);
	c_pth = NULL;
}
