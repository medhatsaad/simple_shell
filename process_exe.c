#include "shell.h"

/**
 * start_proc - starts a new process if a executable is found
 * @av: array of pointers
 */

void start_proc(char **av, char **fold)
{
	pid_t proc;
	char *fullpath = NULL;

	if (av != NULL)
	{
		fullpath = _which(av, fold);

		if(fullpath != NULL)
		{
			proc = fork();

			if (proc == 0)
			{
				if (execve(fullpath, av, NULL) == -1)
				{
					perror("Error");
					exit(-1);
				}
			} else if (proc == -1)
				perror("Failed to fork");
			else
			{
				wait(NULL);
			}
		} else
		{
			perror(": command not found");
		}
		free(fullpath);
	}
}

/**
 * exit_status - exits shell with a status
 * @status: integer
 *
 */

int exit_status(char **av, char **fold)
{
	int status = 0;
	size_t i = 0;

	if (av == NULL)
		return (0);

	if(_strcmp(av[0], "exit")== 0)
	{
		if (av[1] != NULL)
		{
			while (_isdigit(av[1][i]))
				i++;

			if (i == _strlen(av[1]))
			{
				if (av[2] != NULL)
				{
					i = 0;
					while (_isdigit(av[2][i]))
						i++;
					if (i == _strlen(av[2]))
					{
						print("hsh: exit: too many arguments\n");
						return (1);
					}
				}

				status = _atoi(av[1]);
			}
		}

		cleanup(av);
		cleanup(fold);
		exit(status);
	}
	return (0);
}
/**
 * cleanup - frees the memory dynamic array of pointers
 *@buffer: the array to be freed
 */
void cleanup(char **buffer)
{
	int i = 0;

	if (buffer == NULL)
		return;

	while (buffer[i] != NULL)
	{
		free(buffer[i]);
		i++;
	}
	free(buffer);

}
