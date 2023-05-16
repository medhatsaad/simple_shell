#include "shell.h"

void start_proc(char **av)
{
	pid_t proc;

	if (av == NULL)
		exit(0);

if(isapath(av[0]) == 0)
{
	printf("valid\n");
	proc = fork();

	if (proc == 0)
	{
		if (execve(av[0], av, NULL) == -1)
		{
			perror("Error:");
			exit(-1);
		}
	} else if (proc == -1)
		perror("Failed to fork");
	else
	{
		wait(NULL);
	}
} else
	perror("command not found");
}
