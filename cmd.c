#include "shell.h"

int main()
{
	char *cmd = NULL, **av = NULL;
	size_t n = 0;
	int ac;
	pid_t child;


	while (1)
	{
		printf("$ ");

		if (getline(&cmd, &n, stdin) == -1)
		{
			printf("\n");
			exit(0);
		}
		ac = getac(cmd);
		av = getav(cmd, ac, av);

		if(isapath(av[0]) == 0)
		{
			child = fork();

			if (child == 0)
			{
				if (execve(av[0], av, NULL) == -1)
				{
					perror("Error:");
					exit(-1);
				}
			} else if (child == -1)
				perror("Failed to fork");
			else
			{
				wait(NULL);
			}
		} else
			perror("command not found");

	}
	exit(0);
}
