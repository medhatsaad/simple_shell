# include "shell.h"

/**
 * _mexit - exit for NULL values
 * @argv: args to main
 * @av: array of strings
 */

void _mexit(char **av, char **argv)
{
	print(argv[0], 2);
	print(": 1: ", 2);
	print(av[0], 2);
	print(": not found\n", 2);
	_freearr(av);
	if (!(isatty(STDIN_FILENO)))
		exit(127);
}
