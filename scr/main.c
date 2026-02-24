#include "shell.h"
int main(void) {
    char *line;

    while (1)
    {
        line = readline("minishell> ");
        if(!line)
            break;
        char **tokens = tokenize(line);
        if(tokens[0])
            printf("ilk komut: %s\n", tokens[0]);
        free(tokens);        
    }
    printf("exit\n");
    return 0;
}