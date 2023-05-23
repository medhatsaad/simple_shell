#include "shell.h"

int main()
{
	char *cmd = NULL, **av = NULL;
	int ac;
	char **fold = helpwhich();

	while (1)
	{
		cmd = readline(av, fold);
		ac = getac(cmd);

		if (ac > 0)
		{
			av = getav(cmd, ac, av);
			exit_status(av, fold);
			start_proc(av, fold);
		}
	}
	return (0);
}
