# include "main.h"

char **_readline()
{
	size_t size = 0;
	char *line = NULL;
	char **argv;

	if (getline(&line, &size, stdin) == -1)
	{
		free(line);
		exit(-1);
	}
	else if (line[0] == '\n')
		argv = NULL;
	else
		argv = _parse(line);
	free(line);
	return (argv);
}
