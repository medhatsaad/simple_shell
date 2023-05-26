# include "shell.h"
/**
 * _getenv - extract list of directrories from environment variable
 * @_varname: env var name
 * Return: string of DIRs separated by ':"
 */
char *_mgetenv(char *_varname)
{
	int i;
	char *line, *envvar;
	char *value = NULL;

	if (environ == NULL)
		return (NULL);

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
 * _which - search for the path of command
 * @argv: command
 *
 * Return: command appended to path
 */
char *_mwhich(char **argv)
{
	char *pathname, *_wd, *arg0;
	int i;

	arg0 = *argv;
	if (*argv[0] == '/')
	{
		pathname = *argv;
		if (access(pathname, X_OK) == 0)
			return (pathname);
		return (NULL);
	}
	_wd = getcwd(NULL, 0);
	if (arg0[0] == '.' && arg0[1] == '/')
	{
		for (i = 0; arg0[i] != '\0'; i++)
			arg0[i] = arg0[i + 1];
		pathname = _addstring(_wd, *argv);
		free(_wd);
		printf("%s\n", pathname);
		if (access(pathname, X_OK) == 0)
			return (pathname);
		return (NULL);
	}
	free(_wd);
	if (checkbuiltin(argv))
		return ("1");
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
	char **dirarr, *pathname, *path, *msg, *msg1, *msg2, *msg3;
	int i;

	if (argv[0][0] == '/' || argv[0][0] == '.')
		return (argv[0]);
	path = _addstring("/", argv[0]);
	dirarr = _getdirenv();
	if (dirarr == NULL)
		{
			if (_mgetenv("PWD") == NULL)
				msg1 = _addstring("./",program_invocation_short_name);
			else
				msg1 = program_invocation_name;
			msg2 = _addstring(msg1, ": 1: ");
			msg3 = _addstring(msg2,argv[0]);
			msg = _addstring(msg3, ": not found");
			write(STDERR_FILENO,msg,_strlen(msg));
			write(STDERR_FILENO,"\n",1);
			exit(127);
		}
	for (i = 0; dirarr[i] != NULL; i++)
	{
		pathname = _addstring(dirarr[i], path);
		if (access(pathname, F_OK) == 0)
		{
			_freearr(dirarr);
			free(path);
			return (pathname);
		}
		free(pathname);
	}
	_freearr(dirarr);
	free(path);
	return (argv[0]);
}


/**
 * _freearr - free memory assigned for array
 * @arr: array address
 */
void _freearr(char **arr)
{
	int i;

	for (i = 0; arr[i] != NULL; i++)
		free(arr[i]);
	free(arr[i]);
	free(arr);
}
