#ifndef SHELL_H
#define SHELL_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#define BIN "/bin/"
void start_proc(char **av);
int getac(char *str);
char **getav(char *str, int ac, char ** av);
int isapath(char *str);
#endif
