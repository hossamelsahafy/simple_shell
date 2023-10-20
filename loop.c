#include "main.h"

/**
 * loop - function to creat infinty loop
 *
 * @env: parameter that poin to char
*/
void loop(char **env)
{
	char *l = NULL;
	size_t len = 0;
	ssize_t rs = 0;

	while (1)
	{
		rs = getline(&l, &len, stdin);
		comment_handeler(l);
		if (rs == -1)
		{
			write(STDOUT_FILENO, "\n", 1);
			break;
		}
		s_d(l, env);
		free(l);
		l = NULL;
		len = 0;
		write(STDOUT_FILENO, "$ ", 2);
	}
	free(l);
}
