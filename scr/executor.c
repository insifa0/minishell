#include "shell.h"
#include <sys/wait.h>
#include <unistd.h>

void execute(char **args){
    if(args[0] == NULL){
        return;
    }

    pid_t pid = fork();
    if(pid == 0){
        if(execvp(args[0], args) == -1){
            perror("minishell");
        }
        exit(EXIT_FAILURE);
    } else if(pid< 0){
        perror("minishell");
    }else {
        wait(NULL);
    }

}


