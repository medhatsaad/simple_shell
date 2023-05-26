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
	int ac;

	while (1)
	{
		non_interactive(argv);
		cmd = readline();
		ac = getac(cmd);

		av = getav(cmd, ac, av);
		free(cmd);

		if (av != NULL && _strcmp(*av, "exit") == 0)
		{
			exit_status(ac, av, argv);
		} else
			start_proc(av);

	}
	return (0);
}
