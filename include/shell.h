#ifndef SHELL_H
# define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>

void execute(char **args);
char **tokenize(char *line);
int handle_builtins(char **args);

#endif
