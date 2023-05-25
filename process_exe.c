#include "shell.h"
/**
 * exit_status - exits shell with a status
 * @av: arg
 *
 * * Return: 0
 */

void exit_status(char **av)
{
	int status = 0;
	size_t i = 0;

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
					return;
				}
			}

			status = atoi(av[1]);
		}
	}

	_freearr(av);
	exit(status);
}

/**
 * start_proc - starts a new process if a executable is found
 * @av: array of pointers
 */

void start_proc(char **av)
{
	/**char *newenviron[] = {"LANG=en_US.UTF-8", 0};*/
	pid_t proc;
	char *fullpath = NULL;

	if (av != NULL)
	{
		fullpath = _pathchecker(av);

		if (access(fullpath, F_OK) == 0)
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
	int ac, s = 1;

	if (!(isatty(STDIN_FILENO)))
	{
		s = getline(&cmd, &n, stdin);
		while ( s != -1)
		{
			ac = getac(cmd);
			av = getav(cmd, ac, av);

			if (_strcmp(*av, "exit") == 0)
				exit_status(av);
			start_proc(av);
			s = getline(&cmd, &n, stdin);
		}
		free(cmd);
		exit(0);
	}
}
