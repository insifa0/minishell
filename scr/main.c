#include "shell.h"
int main(void) {
    char *line;

    while (1)
    {
        line = readline("minishell> ");
        if(!line)
            break;
        char **tokens = tokenize(line);
        if (tokens[0] != NULL){
            if(!handle_builtins(tokens)){
                execute(tokens);
            }
        }
        free(tokens);        
    }
    printf("exit\n");
    return 0;
}