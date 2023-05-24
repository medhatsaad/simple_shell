#include "shell.h"

char *readline()
{
	char *cmd = NULL;

	print("$ ");

	cmd = _getline();

	if (cmd == NULL)
	{
		print("\n");
		free(cmd);
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
 * print - prints a buffer to the standard output
 * @buff: pointer to the buffer to print
 */
void print(char *buff)
{
	size_t n = 0;

	if (buff != NULL)
	{
		n = _strlen(buff);
		write(1, buff, n);
	}
}
