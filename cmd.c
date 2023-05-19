#include "shell.h"

int main()
{
	char *cmd = NULL, **av = NULL;
       	int ac;

       	while (1)
	{

		cmd = _readline();
		ac = getac(cmd);
		av = getav(cmd, ac, av);

		if (!exit_status(av))
			start_proc(av);
	}
	return (0);
}
