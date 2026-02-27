#include "shell.h"
#include <fcntl.h>

void handle_redirection(char **args){
    for (int i = 0; args[i] != NULL; i++) {
        if (strcmp(args[i], ">") == 0) {
            // Dosyayı aç (yoksa yarat, varsa üzerine yaz)
            int fd = open(args[i + 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
            if (fd < 0) {
                perror("open");
                return;
            }
            dup2(fd, STDOUT_FILENO); // Standart çıktıyı dosyaya yönlendir
            close(fd);
            args[i] = NULL; // > işaretini ve sonrasını exec'ten gizle
            break;
        }
    }
}