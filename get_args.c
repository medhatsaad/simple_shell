#include "shell.h"

char *_readline()
{
	char *cmd = NULL;
	size_t n = 0;

	print("$ ");

	if (getline(&cmd, &n, stdin) == -1)
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

	if(str == NULL)
		return (-1);

	strcp = strdup(str);
	token = strtok(strcp, delim);

	while(token)
	{
		token = strtok(NULL,delim);
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
		av = malloc(sizeof(char *) * (ac + 1));

	i = 0;
       	while(token)
	{
		av[i++] = strdup(token);
		token = strtok(NULL,delim);
	}
	av[i] = NULL;
	free(strcp);
	return (av);
}
