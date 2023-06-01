#include "shell.h"
/**
 * exit_status - exits shell with a status
 * @av: arg
 * @ac: no of arg
 * @argv: main function arg
 *@cmd_count: number of command passed
 * * Return: 0
 */

void exit_status(int ac, char **av, char **argv, int cmd_count)
{
	int status = 0;
	size_t i = 0;

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
			print(argv[0], 2);
			print(": ", 2);
			printInt(cmd_count, 2);
			print(": exit: Illegal number: ", 2);
			print(av[1], 2);
			print("\n", 2);
			_freearr(av);
			exit(2);
		}
	} else if (ac > 2)
	{
		print(argv[0], 2);
		print(": exit: too many arguments\n", 2);
		/* exit(2);*/
	} else
	{
		_freearr(av);
		exit(errno);
	}
}

/**
 * start_proc - starts a new process if a executable is found
 * @av: array of pointers
 *@argv: array of arguments
 */

void start_proc(char **av, char **argv)
{
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
					perror(_getenv("PWD"));
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
		{
			free(fullpath);
			_mexit(av, argv);
			status = 127;
		}
	}
}
/**
 * printInt - prints a positif  integer number into std (out, err)
 *@n: integer to print
 *@std: integer that defines std to print into
 */
void printInt(int n, int std)
{
	char buffer[20], tchar;
	int i = 0, j;


	do {
		buffer[i++] = '0' + (n % 10);
		n /= 10;
	} while (n > 0);


	for (j = 0; j < i / 2; j++)
	{
		tchar = buffer[j];
		buffer[i] = buffer[n - j - 1];
		buffer[n - j - 1] = tchar;
	}

	write(std, buffer, i);
}
