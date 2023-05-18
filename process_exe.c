#include "shell.h"

/**
 * _exit - exits shell with a status
 * @status: integer
 *
int exits(char *status)
{
	if(strcmp(status, "exit\n") == 0 || strcmp(status, "exit ") > 0)
		return (0);
	return (-1);

	if(strcmp(av[0], "exit")== 0)
{
if (av[1]== NULL)
status = 0;
if(av[1][0] == '(' && av[1][strlen(av[1]-1)] == ')' && av[2] == NULL)
status =}
	**/

/**
 * start_proc - starts a new process if a executable is found
 * @av: array of pointers
 */

void start_proc(char **av)
{
	pid_t proc;
	char *fullpath = NULL;

	if (av != NULL)
	{
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
}
void print(char *buff)
{
	size_t n = 0;

	if(buff != NULL)
	{
		n = strlen(buff);
		write(1, buff, n);
	}
}
