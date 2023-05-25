#include "shell.h"

/**
 * main - main function
 * Return: 1
*/
int main(int argc __attribute__((unused)), char **argv __attribute__((unused)))
{
	char *cmd = NULL, **av = NULL;
	int ac;

	while (1)
	{

		non_interactive();
		readline();
		ac = getac(cmd);
		av = getav(cmd, ac, av);
		start_proc(av);
	}
	exit(0);
}
