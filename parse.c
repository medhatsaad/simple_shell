# include "main.h"
/**
 * _evaluate - parse input from getline int array argv
 * @line: pointer to inpute string
 * @size: pointer to size of string include delimetter and new line
 *
 * Return: array of pointers to arguments
 */
char **_parse(char *line)
{
	char **argv;
	int i, argc = 1;
	char *delim = " ";
	char *p = _strcpy(line);
	char *n = _strcpy(line);

	if (strtok(p, delim) != NULL)
	{
		argc++;
		while (strtok(NULL, delim) != NULL)
			argc++;
	}

	argv = malloc(argc * sizeof(char*));
	if (argv)
	{
		argv[0] = strtok(n, delim);
		for (i = 1; i < argc; i++)
		{
			argv[i] = strtok(NULL, delim);
		}
	}
	else
	{
		printf("Can't allocat mem for parse");
		exit(-1);
	}
	return (argv);
}
