#include "shell.h"
/**
 * main - entry point
 *@argc: number of arguments
 *@argv: array of the arguments passed into cmd
 *Return: 0
 */
int main(int argc __attribute__((unused)), char **argv __attribute__((unused)))
{
	char *cmd = NULL, **av = NULL;
	int ac;

	while (1)
	{
		/** non_interactive(); */
		cmd = readline();
		ac = getac(cmd);
		av = getav(cmd, ac, av);
		
		if (!exit_status(av))
			start_proc(av);
	
		free(cmd);
	}
	return (0);
}
