#include "shell.h"
#include <unistd.h>
#include <string.h>

int handle_builtins(char **args) {
    if (args[0] == NULL) return 0;

    if (strcmp(args[0], "exit") == 0) {
        exit(0);
    }

    if (strcmp(args[0], "cd") == 0) {
        if (args[1] == NULL) {
            fprintf(stderr, "minishell: cd: argüman eksik\n");
        } else {
            if (chdir(args[1]) != 0) {
                perror("minishell");
            }
        }
        return 1; // Komut çalıştırıldı
    }

    // env komutu: Tüm ortam değişkenlerini listeler
    if (strcmp(args[0], "env") == 0) {
        extern char **environ; // Ortam değişkenlerine erişim
            for (int i = 0; environ[i] != NULL; i++) {
                printf("%s\n", environ[i]);
            }
        return 1;
    }

    // export komutu: Yeni değişken ekler veya günceller
    if(strcmp(args[0], "export") == 0){
        if(args[1] == NULL){
            fprintf(stderr, "minishell: export: argüman eksik\n");
        } else {
            char *key = strtok(args[1], "=");
            char *value = strtok(NULL, "=");
            
            if (key != NULL && value != NULL) {
                // setenv(anahtar, değer, üzerine_yaz_izni)
                if (setenv(key, value, 1) != 0) {
                    perror("minishell export hatası");
                }
            } else {
                fprintf(stderr, "Kullanım: export ANAHTAR=DEGER\n");
            }
        }
        return 1;
    }

    return 0; // Built-in değil, external komut
}