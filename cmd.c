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
	int ac, cmd_count = 0, mode = 0, status = 0;


	if (isatty(STDIN_FILENO))
		mode = 1;

	errno = 0;

	while (1)
	{
		cmd = readline(mode, cmd_count);
		cmd_count += 1;
		ac = getac(cmd);

		av = getav(cmd, ac, av);
		free(cmd);

		if (av != NULL)
		{
			if (_strcmp(*av, "exit") == 0)
				exit_status(ac, av, argv, cmd_count);
			else
				start_proc(av, argv);
		}
	}
	return (status);
}
