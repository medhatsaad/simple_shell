#include "shell.h"
char *_getenv(char *str);
char **helpwhich();
char *_which(char **av, char **fold);

extern char **environ;

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
 * @ac: Number of arguments.
 * @av: Array of pointers to command line args.
 * Return: The full path of the cmd executable if found.
 */
char **helpwhich()
{
	char **fold = NULL, *delim = ":";
	int i = 0, dir = 0, ln = 0, lnmax = 0;
	size_t k = 0;
	char *path = _getenv("PATH");

	for (; k < _strlen(path); k++)
	{
		if (path[k] == ':')
		{
			lnmax = (ln > lnmax) ? ln : lnmax;
			ln = 0;
			dir++;
		} else
			ln++;
	}

	fold = (char **) malloc(sizeof(char*) * (dir + 2));

	for (i = 0; i < (dir + 1); i++)
	{
		fold[i] = (char*)malloc(lnmax);
		if (fold[i] == NULL)
			return(NULL);
	}
	i = 0;
      	fold[i] = _strtok(path, delim);

	while (fold[i++] != NULL)
	{
		fold[i] = _strtok(NULL, delim);
	}
	fold[i] = NULL;

	return (fold);
}

char *_which(char **av, char **fold)
{

	char *path = NULL;
	int found = 0, i = 0;

	if (access(av[0], F_OK) == 0)
		return(av[0]);

	path = (char *)malloc(_strlen(av[0]) + _strlen(fold[0]) + 2);

	if (path == NULL)
		return(NULL);

	while(found == 0 && fold[i] != NULL)
	{
		_strcpy(path,fold[i]);
		_strcat(path, "/");
		_strcat(path, av[0]);

		if (access(path, F_OK) == 0)
		{
			found = 1;
			return (path);
		}

		i++;
	}
	free(path);
	return (NULL);
}
