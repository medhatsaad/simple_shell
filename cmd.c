#include "shell.h"

int main()
{
	char *cmd = NULL, **av = NULL;
	size_t n = 0;
	int ac;

       	while (1)
	{
		printf("$ ");

		if (getline(&cmd, &n, stdin) == -1 || strcmp("exit\n",cmd) == 0)
	      	{	exit(0);
		}
		ac = getac(cmd);
		av = getav(cmd, ac, av);
		start_proc(av);

	}
	exit(0);
}
