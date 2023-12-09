#ifndef MAIN_H
#define MAIN_H

#define PROMPT "$ "

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

extern char **environ;


char *read_line(void);
char **tokenizeString(char *inputString);
int executeCommand(char **cmd, char **av, int index);
void freeResources(char **tokenArray, int i, char *inputString);
char *_getenv(char *var);
char *_getPath(char *command);

char *_strdup(char *str);
int _strlen(char *str);
void print_error(char *name, char *cmd, int count);
void free2Darray(char **array);
char *_itoa(int count);
void _rev_string(char *s);
#endif
