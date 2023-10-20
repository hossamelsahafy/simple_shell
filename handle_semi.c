#include "main.h"
/**
 * handle_semi - function to handel semicolone
 *
 * @in: parameter that point to char
 *
 * @env: parameter that point to char
 */
void handle_semi(char *in, char **env)
{
	char *c[20];
	int index = 0;

	c[index] = strtok(in, ";");
	while (c[index] != NULL)
	{
		(void)env;
		index++;
		c[index] = strtok(NULL, ";");
	}
	c[index] = NULL;
}
