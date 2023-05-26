# include "shell.h"
/**
 * checkbuiltin - run buildin functions
 * @argv: command
 * Return: 1
 */
int checkbuiltin(char **argv)
{

	if (_strcmp(*argv, "env") == 0)
	{
		_env();
		return (1);
	}
	if (_strcmp(*argv, "setenv") == 0)
	{
		_setenv(argv);
		return (1);
	}
	if (_strcmp(*argv, "unsetenv") == 0)
	{
		_unsetenv(argv);
		return (1);
	}
	if (_strcmp(*argv, "cd") == 0)
	{
		_cd(argv);
		return (1);
	}
	/**
	*	if (_strcmp(*argv, "exit") == 0)
	*	{
	*		exit_status(argv);
	*		return (1);
	*	}
	*/

	return (0);
}

/**
 * _setenv - upsate env variables
 * @argv: command arguments
 */
void _setenv(char **argv)
{
	char *variable, *value, *temp, *newenv;
	int t;

	variable = *(argv + 1);
	value = *(argv + 2);
	t = _ggetenv(variable);
	if (t == -1)
	{
		temp = _addstring(variable, "=");
		newenv = _addstring(temp, value);
		free(temp);
		_realloc(newenv);
	}
	else
	{
		temp = _addstring(":", value);
		environ[t] = _addstring(environ[t], temp);
		free(temp);
	}
}

/**
 * _ggetenv - return index of env var
 * @var: variable name
 *
 * Return: index
 */
int _ggetenv(char *var)
{
	int i = 0, j = -1;
	char *_env;

	while (environ[i])
	{
		_env = _strcp(environ[i]);
		if (_strcmp(strtok(_env, "="), var) == 0)
		{
			j = i;
			break;
		}
		else
		{
			i++;
			free(_env);
		}
	}
	return (j);
}

/**
 * _unsetenv - delete environment variables
 * @argv: command arguments
 */
void _unsetenv(char **argv)
{
	int i = 0, j = 0, l, size = 0, t;
	char *variable;
	char **new;

	variable = *(argv + 1);
	t = _ggetenv(variable);
	if (j != -1)
	{
		for (l = 0; environ[l] != NULL; l++)
			size++;
		new = malloc(sizeof(char *) * size);
		if (!new)
		{
			perror("Allocation fail");
			exit(-1);
		}
		while (environ[j] != NULL)
		{
			if (j != t)
			{
				new[i] = environ[j];
				i++;
				j++;
			}
			else
				j++;
		}
		new[size - 1] = NULL;
		environ = new;
	}
}

/**
 * _realloc - create new copy of environ and add new var
 * @newenv: new var
 */
void _realloc(char *newenv)
{
	int i, size = 0;
	char **new;

	for (i = 0; environ[i] != NULL; i++)
		size++;
	new = malloc(sizeof(char *) * (size + 2));
	if (!new)
	{
		perror("Memory Allocation Fail");
		exit(-1);
	}
	for (i = 0; i < size; i++)
		new[i] = environ[i];
	new[size] = newenv;
	new[size + 1] = NULL;
	environ = new;
}
