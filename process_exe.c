#include "shell.h"

/**
 * exit_status - exits shell with a status
 * @av: arg
 *
 * * Return: 0
 */

int exit_status(char **av)
{
	int status = 0;
	size_t i = 0;

	if (av == NULL)
		return (0);

	if (_strcmp(av[0], "exit") == 0)
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

		for (i = 0; av[i] != NULL; i++)
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
	char *fullpath = NULL;

	if (av != NULL)
	{
		fullpath = av[0];

		if (access(fullpath, X_OK) == 0)
		{
			proc = fork();

			if (proc == 0)
			{
				if (execve(fullpath, av, environ) == -1)
				{
					perror("execution error");
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
			perror(av[0]);
		}

		_freearr(av);
		
	}
}
/**
 *non_interactive - should handle the non interactive mode
 */
void non_interactive(void)
{
	char **av = NULL;
	char *cmd = NULL;
	size_t n = 0;
	int ac;

	if (!(isatty(STDIN_FILENO)))
	{
		if (getline(&cmd, &n, stdin) == -1)
		{
			free(cmd);
			exit(0);
		}
		ac = getac(cmd);
		av = getav(cmd, ac, av);
		start_proc(av);
		exit(0);
	}
}
