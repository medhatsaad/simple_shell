#ifndef SHELL_H
#define SHELL_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <ctype.h>
extern char **environ;
char *isapath(char *path, char *cmd);
void print(char *buff);
void start_proc(char **av);
int getac(char *str);
char **getav(char *str, int ac, char **av);
int exit_status(char **av);
int exits(char *status);
size_t _strlen(char *p);
int _strcmp(char *a, char *b);
char *_strcp(char *p);
char *_addstring(char *a, char *b);
char *_which(char **argv);
char **_getdirenv();
char *_getenv(char *varname);
void _freearr(char **arr);
char *_envcheck(char *argv);
void _env(void);
int checkbuiltin(char **argv);
void _setenv(char **argv);
void _ssetenv(char *variable, char *value);
void _realloc(char *newenv);
void _unsetenv(char **argv);
int _ggetenv(char *var);
void _cd(char **argv);
#endif
