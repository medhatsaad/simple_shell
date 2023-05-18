#include "shell.h"

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
		fullpath = isapath(fullpath, av[0]);

		if(fullpath != NULL)
		{	av[0] = strdup(fullpath);
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
 * print - prints a buffer
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

/**
 * isapath - checks if a given path command is valid
 * @str: command name
 * Return: 0 if it exists and -1 otherwise
 */
char *isapath(char *path, char *cmd)
{
	char *pathcpy = NULL;

	path = "/bin";
	pathcpy = malloc(strlen(path) + strlen(cmd) + 2);

	if (pathcpy == NULL)
		return (NULL);

	strcpy(pathcpy, path);
	strcat(pathcpy, "/");
	strcat(pathcpy, cmd);

	if (access(pathcpy, F_OK) == -1)
	{
		free(pathcpy);
		return (NULL);
	}

	return (pathcpy);
}
