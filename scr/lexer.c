#include "shell.h"
#include <string.h>

char **tokenize(char *line) {
    int bufsize = 64;
    int position = 0;
    char **tokens = malloc(bufsize *sizeof(char*));
    char **token;

    if(!tokens) {
        perror("malloc error");
        exit(1);
    }

    token = strtok(line, "\t\r\n\a");
    while (token != NULL)
    {
        tokens[position] = token;
        position++;

        token = strtok(NULL, "\t\r\n\a");
    }

    tokens[position] = NULL;
    return tokens;    
}