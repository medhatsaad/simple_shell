#ifndef SHELL_H
#define SHELL_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <dirent.h>
#include <errno.h>

#define BUFF_SIZE 1024
extern char **environ;

char *_getline();

char *_getenv(char *str);
char *isapath(char *path, char *cmd);
void print(char *buff);
void start_proc(char **av, char **fold);
int getac(char *str);
char **getav(char *str, int ac, char **av);
int exit_status(char **av, char **fold);
char *readline(char **av, char **fold);
size_t _strlen(char *s);
char *_strcpy(char *dest, char *src);
int _strcmp(char *s1, char *s2);
char *_strdup(char *str);
int _isdigit(int c);
int _atoi(char *s);
int compare_cs(char c, char *str);
char *_strtok(char *str, char* delimit);
char *_strcat(char *dest, char *src);
int _strncmp(char *str1, char *str2, size_t n);
char **helpwhich();
char *_which(char **av, char **fold);
void cleanup(char **buffer);
#endif
