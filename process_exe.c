#include "shell.h"

/**
 * start_proc - starts a new process if a executable is found
 * @av: array of pointers
 */

void start_proc(char **av)
{
	pid_t proc;
	char *fullpath;

	if (av != NULL)
	{
		fullpath = _which(av);
		
		if (fullpath != NULL)
		{	av[0] = _strcp(fullpath);
			free(fullpath);
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
}
/**
 * print - prints a buffer to the standard output
 * @buff: pointer to the buffer to print
 */
void print(char *buff)
{
	size_t n = 0;

	if(buff != NULL)
	{
		n = strlen(buff);
		write(1, buff, n);
	}
}

