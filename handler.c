#include "main.h"
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>

/**
 * handler  - function to handel ctrl c & z
 *
 * @sig: parameter to identify int
 */
void handler(int sig)
{
	(void)sig;
	write(1,"\n$ ", 3);

}
