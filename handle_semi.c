#include "main.h"

void handle_semi(char *i, char **env)
{
    char *c[20];
    int index = 0;

    c[index] = strtok(i, ";");
    while (c[index] != NULL)
	{
		(void)env;
		index++;
		c[index] = strtok(NULL, ";");
	}
	c[index] = NULL;
}
