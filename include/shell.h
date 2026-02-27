#ifndef SHELL_H
# define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <readline/readline.h>
#include <unistd.h>
#include <sys/wait.h>


void execute(char **args);
char **tokenize(char *line);
int handle_builtins(char **args);
void execute_pipeline(char **args1, char **args2);
void setup_signals(void);

#endif
