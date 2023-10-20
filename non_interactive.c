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

	while ((rs = getline(&l, &len, stdin)) != -1)
	{
		if (rs > 1)
		{
			comment_handeler(l);
			if (l[0] != '\0')
			{
				handle_semi(l, env);
				pro_l(l, env);
			}
			free(l);
			l = NULL;
			len = 0;
		}
	}
	free(l);
	return (0);
}
