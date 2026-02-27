#include "shell.h"
#include <sys/wait.h>
#include <unistd.h>

void execute(char **args){
    int background = 0;
    int i = 0;

    // 1. & işaretini kontrol et
    while (args[i] != NULL) {
        if (strcmp(args[i], "&") == 0) {
            background = 1;
            args[i] = NULL; // & işaretini execvp görmemeli
            break;
        }
        i++;
    }

    pid_t pid = fork();
    if(pid == 0){

        handle_redirection(args);

        if(execvp(args[0], args) == -1){
            perror("minishell");
        }
        exit(EXIT_FAILURE);
    } 
    else if(pid< 0){
        perror("minishell");
    }else {
        if (!background) {
            waitpid(pid, NULL, 0); // Arka planda değilse bekle
        } else {
            printf("[Süreç arka planda başlatıldı: %d]\n", pid);
        }
    }

}


