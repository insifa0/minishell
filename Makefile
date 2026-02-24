NAME        = minishell
CC          = gcc
CFLAGS      = -Wall -Wextra -Werror -Iinclude
LDFLAGS     = -lreadline

SRC_DIR     = scr
OBJ_DIR     = obj

SRC_FILES   = main.c lexer.c executor.c execute(tokens);
SRCS        = $(addprefix $(SRC_DIR)/, $(SRC_FILES))
OBJS        = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(LDFLAGS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re


# CFLAGS = -Wall -Wextra -Werror -I include: Bunlar derleyici bayrakları.
# 	-Wall -Wextra: Derleyiciye bize tüm olası uyarıları göstermesini söyler. Bu, potansiyel hataları erkenden yakalamamızı sağlar.
# 	-Werror: Tüm uyarıları birer hataya dönüştürür. Bu bizi daha temiz kod yazmaya zorlar.
# 	-I include: Derleyiciye #include "..." ile eklediğimiz dosyaları include klasörünün içinde aramasını söyler. shell.h dosyasını bu sayede bulacak.
