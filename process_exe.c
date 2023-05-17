#include "shell.h"

/**
 * start_proc - starts a new process if a executable is found
 * @av: array of pointers
 */
void start_proc(char **av)
{
	pid_t proc;
	char *fullpath = NULL;

	if (av == NULL)
		exit(0);

	 fullpath = _which(av);

	 if(fullpath != NULL)
	 {
		av[0] = strdup(fullpath);
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
