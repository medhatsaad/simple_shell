# include "shell.h"
/**
 * checkbuiltin - run buildin functions
 * @argv: command
 * Return: 1
 */
int checkbuiltin(char **argv)
{

	if (_strcmp(argv, "env"))
	{
		_env();
		return (1);
	}
	else
		return(0);
}

