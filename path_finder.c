#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int isapath(char *path, char *cmd);

extern char **environ;

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

	while (*env != NULL) {
		len = strlen(str);
		if (strncmp(str, *env, len) == 0 && (*env)[len++] == '=') {
			value = *env + len;
			break;
		}
		env++;
	}

	return value;
}

/**
 * _which - accesses the PATH env var and searches for the full path of a cmd
 * @ac: Number of arguments.
 * @av: Array of pointers to command line args.
 * Return: The full path of the cmd executable if found.
 */
char **_which(int ac, char **av)
{
	char **fullpath = NULL, *path = NULL, *delim = ":", *token = NULL;
	int i, found = 0;

	path = _getenv("PATH");

	if (ac < 2 || path == NULL)
		return (NULL);

	fullpath = malloc(sizeof(char *) * ac);
	if (fullpath == NULL)
		return (NULL);

	for(i = 0; i < ac; i++)
		fullpath[i] = '\0';

	token = strtok(path, delim);
	while (token != NULL)
	{
		for (i = 1; i < ac; i++)
		{
			if (fullpath[i] == NULL && isapath(token, av[i]) == 0)
			{
				fullpath[i] = strdup(token);
				found = 1;
			}
		}
		token = strtok(NULL, delim);
	}

	if (found)
	{
		/**
		for (i = 1; i < ac; i++)
		{
			if (fullpath[i] != NULL)
			{
				printf("%s\n", fullpath[i]);
				free(fullpath[i]);
			}
		}
		*/
		return (fullpath);
	}

	free(fullpath);
	return (NULL);
}
/**
 *isapath - checks if a given path command is valid
 * @str: command name
 * Return: 0 if it exists and -1 otherwise
 */
int isapath(char *path, char *cmd) {

	char *pathcpy = malloc(strlen(path) + strlen(cmd) + 2);
	if (pathcpy == NULL)
		return (-1);

	strcpy(pathcpy, path);
	strcat(pathcpy, "/");
	strcat(pathcpy, cmd);

	if (access(pathcpy, F_OK) == -1) {
		free(pathcpy);
		return -1;
	}
	free(pathcpy);
	return 0;
}

int main(int argc, char **argv) {

	char **fullPath = _which(argc, argv);

	for(int i = 1; i < argc; i++)
	{
		if (fullPath[i] != NULL)
		{
			printf("Full path of '%s': %s\n", argv[i], fullPath[i]);

		} else {
			printf("Command '%s' not found\n", argv[i]);
		}
	}

	return 0;
}
