# include "main.h"
/**
 * main - main function
 * Return - 0
 */
int main()
{
	while (1)
	{
		char **argv;
		char *prompt = "($) ";

		write(STDOUT_FILENO,prompt,4);
		argv = _readline();
		if (argv != NULL)
			_print(argv);
	}
	return (0);
}
