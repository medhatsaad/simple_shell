#include "shell.h"

int main()
{
	char *cmd = NULL, *cmdcpy = NULL, *token = NULL, **av = NULL;
	char *delim = " \n";
	size_t n = 0;
	int ac, status;
	pid_t child;


	while (1)
	{
		printf("$ ");

		if (getline(&cmd, &n, stdin) == -1)
		{
			printf("\n");
			exit(0);
		} else if (*cmd == '\n')
			av = NULL;

		cmdcpy = strdup(cmd);
		token = strtok(cmdcpy, delim);
		ac = 0;

		while(token)
		{
			token = strtok(NULL,delim);
			ac++;
		}
		av = realloc(av, sizeof(char *) *ac);

		token = strtok(cmd, delim);
	        ac = 0;
		while(token)
		{
			av[ac++] = token;
			token = strtok(NULL,delim);
		}
		av[ac] = NULL;
		child = fork();

		if (child == 0)
		{
			if (execve(av[0], av, NULL) == -1)
			{
				perror("Error:");
			}
		} else if (child == -1)
			perror("Failed to fork");
		else
		{
			wait(NULL);
			while (ac)
				free(av[--ac]);
		}
	}
	exit(0);
}
