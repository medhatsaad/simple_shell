# include "main.h"
/**
 * _print - excute the command in argv
 * @argv: arguments pointer
 *
 * Return: none
 */
int _print(char **argv)
{
	char *const envp[] = {NULL};
	char *pathname;
	char *path = "/bin/";
	int fd;

	pathname = _addstring(path , argv[0]);
	fd = open(pathname, O_RDONLY);
	if (fd < 0)
		write(STDOUT_FILENO, "File Not Exist",14);
	else
	{
		close(fd);
		_exec(pathname, argv, envp);
	}
	return (0);
}

void _exec(char *pathname, char **argv, char *const envp[])
{
	pid_t pid;

	pid = fork();
	if ( pid == -1)
		exit(-1);
	if (pid == 0)
		execve(pathname, argv, envp);
	else
		wait(NULL);
	
}
