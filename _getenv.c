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
