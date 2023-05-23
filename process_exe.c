#include "shell.h"

/**
 * exit_status - exits shell with a status
 * @status: integer
 *
 */

int exit_status(char **av)
{
	int status = 0;
	size_t i = 0;

	if (av == NULL)
		return (0);

	if(strcmp(av[0], "exit")== 0)
	{
		if (av[1] != NULL)
		{
			while (isdigit(av[1][i]))
				i++;

			if (i == strlen(av[1]))
			{
				if (av[2] != NULL)
				{
					i = 0;
					while (isdigit(av[2][i]))
						i++;
					if (i == strlen(av[2]))
					{
						print("hsh: exit: too many arguments\n");
						return (1);
					}
				}

				status = atoi(av[1]);
			}
		}

		for(i = 0; av[i] != NULL; i++)
			free(av[i]);
		exit(status);
	}
	return (0);
}
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
		
		if (_strcmp(fullpath, "1") != 0)
		{
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
