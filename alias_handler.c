#include "main.h"

/**
 * alias_handler - function to handel alias
 *
 * @shell: parameter point to struct
 *
 * @ars: parameter that point  to char
*/
void alias_handler(Shell *shell, char **ars)
{
	int i, j;
	char c;

	if (ars[1] == NULL)
	{
		for (i = 0; i < shell->alias_c; i++)
		{
			for (j = 0; shell->aliases[i].name[j] != '\0'; j++)
			{
				write(STDOUT_FILENO, &shell->aliases[i].name[j], 1);
			}
			c = '=';
			write(STDOUT_FILENO, &c, 1);
			c = '\'';
			write(STDOUT_FILENO, &c, 1);
			for (j = 0; shell->aliases[i].value[j] != '\0'; j++)
			{
				write(STDOUT_FILENO, &shell->aliases[i].value[j], 1);
			}
			c = '\'';
			write(STDOUT_FILENO, &c, 1);
			c = '\n';
			write(STDOUT_FILENO, &c, 1);
		}
	}
}
