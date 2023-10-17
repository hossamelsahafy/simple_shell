#include "main.h"

/**
 * loop - function to creat infinty loop
 *
 * @env: parameter that poin to char
*/
void loop(char **env)
{
	char **ts = NULL;
	char *l = NULL;
	size_t len = 0;
	ssize_t rs = 0;

	while (1)
	{
		rs = getline(&l, &len, stdin);
		if (rs == -1)
		{
			write(STDOUT_FILENO, "\n", 1);
			break;
		}
		if (l[0] == '\n')
		{
			write(STDOUT_FILENO, "cisfun$ ", 8);
			continue;
		}
		ts = p_l(l);
		if (c_b(ts[0]) == 1)
		{
			e_b(ts, env);
		}
		else
		{
			execute(ts, env);
		}
		free(ts);
		ts = NULL;
		l = NULL;
		len = 0;
		write(STDOUT_FILENO, "cisfun$ ", 8);
	}
	free(l);
}
