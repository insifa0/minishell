#include "shell.h"
#include <signal.h>
#include <readline/history.h>

void handle_sigint(int sig) {
    (void)sig;
    printf("\nminishell> ");
    fflush(stdout);
}

void setup_signals(void){
    signal(SIGINT, handle_sigint);
    signal(SIGTSTP, SIG_IGN);
}


void print_welcome_screen() {
    printf("\033[1;36m"); 
    printf("____________________________________________________\n\n");
    printf("    __  ____       _   _____ __         ____        \n");
    printf("   /  |/  (_)___  (_) / ___// /_  ___  / / /        \n");
    printf("  / /|_/ / / __ \\/ /  \\__ \\/ __ \\/ _ \\/ / /         \n");
    printf(" / /  / / / / / / /  ___/ / / / /  __/ / /          \n");
    printf("/_/  /_/_/_/ /_/_/  /____/_/ /_/\\___/_/_/           \n");
    printf("                                                    \n");
    printf("       >>> Version 1.0 - insifa0 <<<                \n");
    printf("____________________________________________________\n");
    printf("\033[0m\n");
}


int main(void) {
    setup_signals();
    print_welcome_screen();
    char *line;

    while (1)
    {
        char cwd[1024];
        getcwd(cwd, sizeof(cwd));
        printf("\033[1;32m%s\033[0m ", cwd);
        // 1. Kullanıcıdan girdiyi al (Silinen kısım buydu)
        line = readline("minishell> ");
        
        // 2. Ctrl+D (EOF) kontrolü
        if (!line) {
            break;
        }

        if(line[0] != '\0'){
            add_history(line);
        }

        char **tokens = tokenize(line);
        
        if (tokens[0] != NULL) {
            int pipe_idx = -1;
            
            // 1. Adım: Pipe (|) işaretini ara
            for (int i = 0; tokens[i] != NULL; i++) {
                if (strcmp(tokens[i], "|") == 0) {
                    pipe_idx = i;
                    break;
                }
            }

            if (pipe_idx != -1) {
                // 2. Adım: Pipe bulundu, diziyi ikiye böl!
                tokens[pipe_idx] = NULL; 
                char **args2 = &tokens[pipe_idx + 1]; 
                
                // 3. Adım: Pipeline fonksiyonunu çağır
                execute_pipeline(tokens, args2);
            } else {
                // Pipe yoksa normal akışa devam et
                if (!handle_builtins(tokens)) {
                    execute(tokens);
                }
            }
        }
        free(tokens);
        free(line);     
    }
    printf("exit\n");
    return 0;
}

