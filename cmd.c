#include "shell.h"

/**
 * main - entry point
 *@argc: number of arguments
 *@argv: array of the arguments passed into cmd
 *Return: 0
 */
int main(int argc __attribute__((unused)), char **argv)
{
	char *cmd = NULL, **av = NULL;
	int ac, mode = 0;


	if (isatty(STDIN_FILENO))
		mode = 1;

	errno = 0;


	while (1)
	{
		non_interactive(argv, mode);
		cmd = readline(mode);
		ac = getac(cmd);

		av = getav(cmd, ac, av);
		free(cmd);

		if (av != NULL)
		{
			if (_strcmp(*av, "exit") == 0)
				exit_status(ac, av, argv);
			else
				start_proc(av);
		}
	}
	return (0);
}
