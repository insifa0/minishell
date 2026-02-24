#include "shell.h"
#include <unistd.h>

int handle_builts(char **args){
    if(args[0] == NULL) return 0;
    if(strcmp(args[0], "exit") == 0){
        exit(0);
    }
    if(strcmp(args[0], "cd") == 0){
        if(args[1]== NULL){
            fprintf(stderr, "minishell: cd: argüman eksik\n");
        } else {
            if(chdir(args[1]) != 0){
                perror("minishell");
            }
        }
        return 1;
    }
    return 0;
}