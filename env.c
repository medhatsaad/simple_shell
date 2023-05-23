# include "shell.h"
/**
 * _env  - list env variables
 *
 * Return:1
 */
void  _env(void)
{
	int i;

	for (i = 0 ; environ[i] != NULL; i++)
	{
		write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
	}
}

void _cd(char **argv)
{
	char *_dir, *_wd, *pathname;

	_dir = *(argv + 1);
	_wd = getcwd(NULL, 0);
	if(_dir)
	{
		if (_strcmp(_dir, "-"))
			pathname = _getenv("HOME");
		else if (_dir[0] == '/')
			pathname = _dir;
		else
			pathname = _addstring(_wd, _dir);
	}
	else
		pathname = _getenv("HOME");
	chdir(pathname);
	_ssetenv("PWD", pathname);
	free(_wd);
}


/**
 * _ssetenv - upsate env variables
 * @argv: command arguments
 */
void _ssetenv(char *variable, char *value)
{
	char *temp, *newenv;
	int t;

	t = _ggetenv(variable);
	if (t == -1)
	{
		temp = _addstring(variable, "=");
		newenv = _addstring(temp, value);
		free(temp);
		_realloc(newenv);
	}
	else
		environ[t] = _addstring("PWD=", value);
}

