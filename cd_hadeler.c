#include "main.h"

/**
 * handle_cd - function to handel cd
 *
 * @ts: parameter that point to char
 *
 * Return: 1 if it fails otherwise 0
 */

int handle_cd(char **ts)
{

	if (ts[1] == NULL)
	{
		perror("ERRNO");
		return (1);
	}
	else
	{
		if (chdir(ts[1]) != 0)
		{
			perror("cd");
			return (1);
		}
	}
	return (0);
}

