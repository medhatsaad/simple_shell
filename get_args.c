#include "shell.h"

char *readline(char **av, char **fold);
int getac(char *str);
char **getav(char *str, int ac, char **av);
char *readline();
void print(char *buff);



char *readline(char **av, char **fold)
{
	char *cmd = NULL;

	print("$ ");

	cmd = _getline();
	printf("%s\n", cmd);
	if (cmd == NULL)
	{
		print("\n");
		free(cmd);
		cleanup(fold);
		cleanup(av);
		exit(0);
	}
	return (cmd);
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

	if(str == NULL)
		return (-1);

	strcp = _strdup(str);
	token = _strtok(strcp, delim);

	while(token)
	{
		token = _strtok(NULL,delim);
		ac++;
	}
	free(strcp);
	return (ac);
}

/**
 * getav - gets the array arguments
 * @str: string to divide into args
 * Return: array of pointers
 */
char **getav(char *str, int ac, char **av)
{
	int i = 0;
	char *token, *strcp, *delim = " \n";

	if (ac > 0)
	{
		if (av == NULL)
			av = malloc(sizeof(char *) * (ac + 1));
		else
			av = realloc(av, sizeof(char *) * (ac + 1));
		if (av == NULL)
			return (NULL);
	} else
		return (NULL);

	strcp = _strdup(str);

	token = _strtok(strcp, delim);

	while(token)
	{
		av[i++] = _strdup(token);
		token = _strtok(NULL,delim);
	}
	av[i] = NULL;
	free(strcp);
	return (av);
}


char *_getline()
{
	static char buffer[BUFF_SIZE];
	static ssize_t scanned = 0;
	static ssize_t cursor = 0;

	ssize_t i = 0;
	char* line = NULL;


	while(1)
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
			line = realloc(line, (i + 1) * sizeof(char));
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
 * print - prints a buffer to the standard output
 * @buff: pointer to the buffer to print
 */
void print(char *buff)
{
	size_t n = 0;

	if(buff != NULL)
	{
		n = _strlen(buff);
		write(1, buff, n);
	}
}

