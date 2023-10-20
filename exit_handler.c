#include "main.h"

/**
 * exit_handler - function to handel exit builtin
 *
 * @ts: parameter that point to char
 */

void exit_handler(char **ts)
{
	int  i;
	int status = 0;

	if (ts[1] != NULL)
	{
		status = _atoi(ts[1]);
	}
	for (i = 0; ts[i] != NULL; i++)
	{
		free(ts[i]);
	}
	free(ts);
	exit(status);
}

