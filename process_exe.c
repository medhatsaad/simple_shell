#include "shell.h"
/**
 * exit_status - exits shell with a status
 * @av: arg
 * @ac: no of arg
 * @argv: main function arg
 *
 * * Return: 0
 */

void exit_status(int ac, char **av, char **argv)
{
	int status = 0;
	size_t i = 0;

	if (ac > 2)
	{
		print(argv[0]);
		print(": exit: too many arguments\n");
		exit(2);
	}

	if (ac == 2)
	{
		while (_isdigit(av[1][i]))
			i++;

		if (i == _strlen(av[1]))
		{
			status = _atoi(av[1]);
			_freearr(av);
			exit(status);
		}
		else
		{
			print(argv[0]);
			print(": 1: exit: Illegal number: ");
			print(av[1]);
			print("\n");
			_freearr(av);
			exit(2);
		}
	}

	_freearr(av);
	exit(errno);
}

/**
 * start_proc - starts a new process if a executable is found
 * @av: array of pointers
 */

void start_proc(char **av)
{
	/**char *newenviron[] = {"LANG=en_US.UTF-8", 0};*/
	pid_t proc;
	int status;
	char *fullpath = NULL;

	if (av != NULL)
	{
		fullpath = _mwhiche(av);

		if (fullpath != NULL)
		{
			proc = fork();

			if (proc == 0)
			{
				status = execve(fullpath, av, environ);

				if (status == -1)
				{
					perror("execution error");
					exit(2);
				}
			} else if (proc == -1)
				perror("Failed to fork");
			else
			{
				wait(&status);

				if (WIFEXITED(status))
					errno = WEXITSTATUS(status);
			}
		_freearr(av);
		free(fullpath);
		}
		else
			_mexit(av, fullpath);
	}
}
/**
 * non_interactive - should handle the non interactive mode
 * @argv: arguments
 *@mode: specifies the mode
 */
void non_interactive(char **argv, int mode)
{
	char **av = NULL;
	char *cmd = NULL;
	size_t n = 0;
	int ac;

	if (mode == 0)
	{
		if (getline(&cmd, &n, stdin) == -1)
		{
			_freearr(av);
			free(cmd);
			exit(0);
		}
		ac = getac(cmd);
		av = getav(cmd, ac, av);
		free(cmd);
		cmd = NULL;
		if (av != NULL)
		{
			if (_strcmp(*av, "exit") == 0)
				exit_status(ac, av, argv);
			else
				start_proc(av);
			/*s = getline(&cmd, &n, stdin);*/
		}
	}
}
