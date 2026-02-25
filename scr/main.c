#include "shell.h"
int main(void) {
    char *line;

    while (1)
    {
        // 1. Kullanıcıdan girdiyi al (Silinen kısım buydu)
        line = readline("minishell> ");
        
        // 2. Ctrl+D (EOF) kontrolü
        if (!line) {
            break;
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