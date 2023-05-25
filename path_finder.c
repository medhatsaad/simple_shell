#include "shell.h"

/**
 * _getenv - gets the value of an environment variable.
 * @str: string representing the key of the environment variable.
 * Return: The corresponding value of the key if it exists or NULL not.
 **/
char *_getenv(char *str)
{
	char *value = NULL;
	size_t len;
	char **env = environ;

	while (*env != NULL)
	{
		len = _strlen(str);
		if (_strncmp(str, *env, len) == 0 && (*env)[len++] == '=')
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
 * @av: Array of pointers to command line args.
 * Return: The full path of the cmd executable if found.
 */
char *_which(char **av)
{
	char *fullpath = NULL, *path = NULL, *pathdup, *delim = ":", *token = NULL;
	int found = 0;

	pathdup = _getenv("PATH");
	path = _strdup(pathdup);
	token = _strtok(path, delim);

	while (token != NULL)
	{
		fullpath = isapath(token, av[0]);
		if (found == 0 && fullpath != NULL)
		{
			found = 1;
			break;
		}
		token = _strtok(NULL, delim);
	}
	free(path);
	if (found)
		return (fullpath);

	return (NULL);
}

/**
 *isapath - checks if a given path command is valid
 * @path: directory path
 *@cmd: command name
 * Return: full path of the executable
 */
char *isapath(char *path, char *cmd)
{

	char *pathcpy = NULL;


	if (access(cmd, F_OK) == 0)
		return (cmd);

	pathcpy = (char *) malloc(_strlen(path) + _strlen(cmd) + 2);

	if (pathcpy == NULL)
		return (NULL);

	_strcpy(pathcpy, path);
	_strcat(pathcpy, "/");
	_strcat(pathcpy, cmd);


	if (access(pathcpy, F_OK) == -1)
	{
		free(pathcpy);
		return (NULL);
	}
	return (pathcpy);
}
