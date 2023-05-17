#include "shell.h"

/**
 * _getenv - gets the value of an environment variable.
 * @str: string representing the key of the environment variable.
 * Return: The corresponding value of the key if it exists or NULL not.
 */
char *_getenv(char *str)
{
	char **env = environ;
	char *value = NULL;
	int len;

	while (*env != NULL)
	{
		len = strlen(str);
		if (strncmp(str, *env, len) == 0 && (*env)[len++] == '=')
		{
			value = *env + len;
			break;
		}
		env++;
	}
	return (value);
}

/**
 * _which - accesses the PATH env var and searches for the full path of a cmd
 * @ac: Number of arguments.
 * @av: Array of pointers to command line args.
 * Return: The full path of the cmd executable if found.
 */
char *_which(char **av)
{
	char *fullpath = NULL, *path = NULL, *delim = ":", *token = NULL;
	int found = 0;

	path = _getenv("PATH");

	token = strtok(path, delim);

	while (token != NULL)
	{
		if (fullpath == NULL && isapath(token, av[0]) != NULL)
		{
			fullpath = strdup(isapath(token, av[0]));
			av[0] = strdup(fullpath);
			found = 1;
			break;
		}
		token = strtok(NULL, delim);
	}
	free(fullpath);
	if (found)
		return (av[0]);

	return (NULL);
}
/**
 *isapath - checks if a given path command is valid
 * @str: command name
 * Return: 0 if it exists and -1 otherwise
 */
char *isapath(char *path, char *cmd)
{

	char *pathcpy = malloc(strlen(path) + strlen(cmd) + 2);

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
