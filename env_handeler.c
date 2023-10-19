#include "main.h"

/**
 * handle_env - function to handel env
 *
 * @env: parameter that point to char
 *
 * Return: if eenv == NULL will be 1 otherwise 0
 */
int handle_env(char **env)
{

	int i;
	const char *env_v;
	size_t env_v_l;

	if (env == NULL)
	{
		perror("env");
		return (1);
	}
	for (i = 0; env[i] != NULL; i++)
	{
		env_v = env[i];
		env_v_l = _strlen(env_v);
		write(1, env_v, env_v_l);
		write(1, "\n", 1);
	}
	return (0);
}
