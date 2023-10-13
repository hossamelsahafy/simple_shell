#include "main.h"
/**
 * loop - function to creat infinty loop
 * 
 * @env: parameter that point to char
*/
void loop(char **env)
{
    int p = 0;
    char *cmd[MAX_C][MAX_A];
	char *l = NULL;
	char **ts = NULL;
	size_t len = 0;
	ssize_t rs = 0;

    while (1)
    {
        write(STDOUT_FILENO, "cisfun$", 7);
		rs = getline(&l, &len, stdin);
		if (rs == -1)
		{
			write(STDOUT_FILENO, "\n", 1);
			break;
		}
		if (l[0] == '\n')
		{
			continue;
		}
		pipes(l, cmd, p);
		if (p > 0)
		{
			execute_pipes(cmd, p);
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
	}
}