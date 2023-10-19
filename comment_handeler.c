#include "main.h"

/**
 * comment_handeler - function to handel comment in shell
 *
 * @ts: parameter that point to char
 */

void comment_handeler(char **ts)
{
	int i;
	char *command;

	for (i = 0; ts[i] != NULL; i++)
	{
		command = _strchr(ts[i], '#');
		if (command != NULL)
		{
			*command = '\0';
		}
	}
}
