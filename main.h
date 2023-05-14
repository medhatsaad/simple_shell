# ifndef _FILE_NAME_H_
# define _FILE_NAME_H_
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <sys/wait.h>
# include <fcntl.h>
void add();
char **_readline();
char **_parse(char *line);
char *_strcpy(char *p);
int _print(char **argv);
char *_addstring(char *a, char *b);
void _exec(char *pathname, char **argc, char *const envp[]);
# endif
