# include "shell.h"
/**
 * _mexit - exit for NULL values
 * @argv: arg
 * @p: pointer
 */
void _mexit(char **argv, char *p)
{
	char *msg, *msg1, *msg2, *msg3, *_pwd;

	_pwd = _mgetenv("PWD");
	if (_pwd == NULL)
		msg1 = _addstring("./", program_invocation_short_name);
	else
		msg1 = _strcp(program_invocation_name);
	msg2 = _addstring(msg1, ": 1: ");
	msg3 = _addstring(msg2, argv[0]);
	msg = _addstring(msg3, ": not found");
	write(STDERR_FILENO, msg, _strlen(msg));
	write(STDERR_FILENO, "\n", 1);
	free(msg);
	free(msg1);
	free(msg2);
	free(msg3);
	free(p);
	free(_pwd);
	_freearr(argv);
	if (!(isatty(STDIN_FILENO)))
		exit(127);
}


