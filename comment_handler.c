#include "main.h"

/**
 * comment_handeler - function to handel comment
 *
 * @ts: parameter that point to char
 */

void comment_handeler(char *ts)
{
	int i = 0;

	if (ts == NULL)
	{
		return;
	}
	while (ts[i] == ' ')
	{
		i++;
	}
	if (ts[i] == '#')
	{
		ts[i] = '\0';
		return;
	}
	for (i = 0; ts[i] != '\0'; i++)
	{
		if (ts[i] == '#' && ts[i - 1] == ' ')
		{
			ts[i] = '\0';
			return;
		}
	}
}
