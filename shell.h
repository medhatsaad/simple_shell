#ifndef SHELL_H
#define SHELL_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <ctype.h>
#include <sys/stat.h>
#include <errno.h>



extern char **environ;
extern char *program_invocation_name;
extern char *program_invocation_short_name;
#define BUFF_SIZE 1024

extern int status;
char *_getline();
char *readline(int mode, int cmd_count);
char *isapath(char *path, char *cmd);
void print(char *buff, int i);
void start_proc(char **av, char **argv);
int getac(char *str);
char **getav(char *str, int ac, char **av);
void exit_status(int ac, char **av, char **argv, int cmd_count);
void printInt(int n, int std);
size_t _strlen(char *p);
int _strcmp(char *a, char *b);
char *_strcp(char *p);
char *_strdup(char *p);
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
char *_strcpy(char *dest, char *src);
int _isdigit(int c);
int _atoi(char *s);
int compare_cs(char c, char *str);
char *_strtok(char *str, char *delimit);
char *_strcat(char *dest, char *src);
int _strncmp(char *str1, char *str2, size_t n);
void _freearr(char **arr);
char *_pathchecker(char **argv);
char **_getdirenv();
char *_mgetenv(char *_varname);
char *_mwhiche(char **av);
void _mexit(char **av, char **argv);
char *_strtrim(char *p);






















#endif
