#include "shell.h"

/**
 * readline - get line from stdin
 *@mode: specifies the mode
 *@cmd_count: number of command passed
 * Return: string
*/
char *readline(int mode, int cmd_count)
{
	char *cmd = NULL;
	size_t n = 0;

	if (mode == 1)
		print("($) ", 1);
	if (getline(&cmd, &n, stdin) == -1)
	{
		cmd_count += 1;
		free(cmd);
		exit(0);
	}
	return (cmd);
}
/**
 *_getline - reads from the stdin
 *Return: cmd
 */

char *_getline()
{
	static char buffer[BUFF_SIZE];
	static ssize_t scanned;
	static ssize_t cursor;

	ssize_t i = 0;
	char *line = NULL;

	while (1)
	{
		if (cursor == scanned)
		{
			scanned = read(0, buffer, BUFF_SIZE);

			if (scanned <= 0)
			{
				if (line != NULL)
					free(line);
				return (NULL);
			}
		}

		cursor = 0;
		while (cursor < scanned)
		{
			line = (char *) realloc(line, (i + 1) * sizeof(char));
			line[i++] = buffer[cursor];

			if (buffer[cursor] == '\n')
			{
				cursor++;
				line[i] = '\0';
				return (line);
			}
			cursor++;
		}
	}
}

/**
 * getac - gets the number of arguments passed into the cmd
 * @str: string to check
 * Return: number of argc
 */
int getac(char *str)
{
	char *strcp = NULL, *token, *delim = " \n";
	int ac = 0;

	if (str == NULL)
		return (-1);

	strcp = _strdup(str);
	token = _strtok(strcp, delim);

	while (token)
	{
		token = _strtok(NULL, delim);
		ac++;
	}
	free(strcp);
	return (ac);
}

/**
 * getav - gets the array arguments
 * @str: string to divide into args
 *@ac: number of arguments
 *@av: previous array of argument
 * Return: array of pointers
 */
char **getav(char *str, int ac, char **av)
{
	int i = 0;
	char *token, *strcp, *delim = " \n";

	if (ac > 0)
	{
		av = malloc(sizeof(char *) * (ac + 1));
	/**
	 *	 if (av == NULL)
	 *	   av = malloc(sizeof(char *) * (ac + 1));
	 *	   else
	 *	   av = realloc(av, sizeof(char *) * (ac + 1));
	 */
		if (av == NULL)
			return (NULL);
	} else
		return (NULL);

	strcp = _strdup(str);

	token = _strtok(strcp, delim);

	while (token)
	{
		av[i++] = _strdup(token);
		token = _strtok(NULL, delim);
	}
	av[i] = NULL;
	free(strcp);
	return (av);
}

/**
 * print - prints a buffer to the standard std (out, err)
 * @buff: pointer to the buffer to print
 * @i: integer that takes 1 for stdout and 2 for stderr
 */
void print(char *buff, int i)
{
	size_t n = 0;

	if (buff != NULL)
	{
		n = _strlen(buff);
		write(i, buff, n);
	}
}
