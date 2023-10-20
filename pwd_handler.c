#include "main.h"

/**
 * pwd_handeler - function to handle the current directory
 */

void pwd_handler(void)
{
	char cwd[1024];

	if (getcwd(cwd, sizeof(cwd)) != NULL)
	{
		write(STDOUT_FILENO, cwd, _strlen(cwd));
		write(STDOUT_FILENO, "\n", 1);
	}
	else
	{
		perror("getcwd() error");
	}
}
