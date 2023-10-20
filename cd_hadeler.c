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
	char cwd[1024];
	char *pth = ts[1];

	if (pth == NULL)
	{
		pth = getenv("HOME");
	}
	else if (strcmp(pth, "-") == 0)
	{
		pth = getenv("OLDPWD");
	}
	if (chdir(pth) != 0)
	{
		perror("cd");
		return (1); 
	}
	if (getcwd(cwd, sizeof(cwd)) != NULL)
	{
		setenv("PWD", cwd, 1);
	}
	else
	{
		perror("getcwd() error");
		return (1);
	}
	return (0);
}

