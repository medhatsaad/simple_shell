#include "shell.h"

/**
 * main - main function
 * Return: 1
*/
int main(void)
{
	char *cmd = NULL, **av = NULL;
	int ac;

	size_t n = 0;

	while (1)
	{
		print("($) ");

		if (getline(&cmd, &n, stdin) == -1)
		{
			print("\n");
			free(cmd);
			exit(0);
		}

		ac = getac(cmd);
		av = getav(cmd, ac, av);
		start_proc(av);

	}
	exit(0);
}
