# include "shell.h"
/**
 * _mgetenv - extract list of directrories from environment variable
 * @_varname: env var name
 * Return: string of DIRs separated by ':"
 */
char *_mgetenv(char *_varname)
{
	int i;
	char *line, *envvar;
	char *value = NULL;

	for (i = 0 ; environ[i] != NULL; i++)
	{
		line = _strcp(environ[i]);
		envvar = strtok(line, "=");
		if (_strcmp(envvar, _varname) == 0)
		{
			value = _strcp(strtok(NULL, "="));
			free(line);
			return (value);
		}
		free(line);
	}
	return (NULL);
}

/**
 * _getdirenv - parse dir list string into an array
 *
 * Return: array of DIRs
 */
char **_getdirenv()
{
	int i, size;
	char *dirname, *dirlist, *_dirlist;
	char **dirarr = NULL;

	dirlist = _mgetenv("PATH");

	if (dirlist == NULL)
		return (NULL);

	_dirlist = _strcp(dirlist);
	if (strtok(_dirlist, ":") != NULL)
	{
		size = 1;
		while (strtok(NULL, ":") != NULL)
			size++;
	}
	free(_dirlist);

	dirarr = malloc(sizeof(char *) * (size + 1));
	if (!dirarr)
	{
		perror("Allocation Fail");
		exit(-1);
	}

	dirname = strtok(dirlist, ":");
	for (i = 0; dirname != NULL; i++)
	{
		dirarr[i] = _strcp(dirname);
		dirname = strtok(NULL, ":");
	}
	dirarr[i] = NULL;
	free(dirlist);
	return (dirarr);
}

/**
 * _mwhiche - search for the path of command
 * @argv: command
 *
 * Return: command appended to path
 */
char *_mwhiche(char **argv)
{
	char *pathname;

	if (argv[0][0] == '/' || argv[0][0] == '.')
	{
		if (access(argv[0], X_OK) == 0)
			pathname = _strcp(argv[0]);
		else
			pathname = NULL;
		return (pathname);
	}

	if (checkbuiltin(argv))
	{
		pathname = NULL;
		return (pathname);
	}
	else
		return (_pathchecker(argv));
}


/**
 * _pathchecker - check command vs path env
 * @argv: input command
 * Return: full path
 */
char *_pathchecker(char **argv)
{
	char **dirarr, *pathname, *path, *_pathname;
	int i;


	dirarr = _getdirenv();
	if (dirarr == NULL || environ == NULL)
	{
		pathname = NULL;
		return (pathname);
	}
	path = _addstring("/", argv[0]);
	for (i = 0; dirarr[i] != NULL; i++)
	{
		_pathname = _addstring(dirarr[i], path);
		if (access(_pathname, X_OK) == 0)
		{
			pathname = _strcp(_pathname);
			_freearr(dirarr);
			free(path);
			free(_pathname);
			return (pathname);
		}
		free(_pathname);
	}
	_freearr(dirarr);
	free(path);
	pathname = NULL;
	return (pathname);
}


/**
 * _freearr - free memory assigned for array
 * @arr: array address
 */
void _freearr(char **arr)
{
	int i;

	if (arr == NULL)
		return;
	for (i = 0; arr[i] != NULL; i++)
		free(arr[i]);
	free(arr[i]);
	free(arr);
}
