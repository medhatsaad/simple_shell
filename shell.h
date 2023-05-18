#ifndef SHELL_H
#define SHELL_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

extern char **environ;
char *_getenv(char *str);
char *_which(char **av);
char *isapath(char *path, char *cmd);
void print(char *buff);
void start_proc(char **av);
int getac(char *str);
char **getav(char *str, int ac, char **av);
int exits(char *status);
#endif
