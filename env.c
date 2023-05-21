# include "shell.h"
/**
 * _env  - list env variables
 *
 * Return:1
 */
void  _env(void)
{
	int i;

	for (i = 0 ; environ[i] != NULL; i++)
	{
		write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
	}
}


