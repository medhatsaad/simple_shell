#include "shell.h"
/**
 * main - entry point
 */
int main(int argc __attribute__((unused)), char **argv __attribute__((unused)))
{
	char *cmd = NULL, **av = NULL;
	int ac;

	while (1)
	{
		non_interactive();
	       	cmd = readline();
		ac = getac(cmd);
		av = getav(cmd, ac, av);

		if (!exit_status(av))
			start_proc(av);
	}
	return (0);
}
