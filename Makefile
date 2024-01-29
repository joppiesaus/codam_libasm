NAME=libasm.a
ASM=nasm
SRC_DIR=src # TODO
# SRCS=$(wildcard *.s)
SRCS=ft_strlen.s ft_strcmp.s ft_strcpy.s ft_strdup.s ft_write.s ft_read.s
OBJ_DIR=obj
OBJ=$(SRCS:%.s=$(OBJ_DIR)/%.o)
CC=gcc

all: $(NAME)

$(NAME): $(OBJ)
	ar -rcs $@ $^

$(OBJ_DIR)/%.o: %.s | $(OBJ_DIR)
	$(ASM) -felf64 $< -o $@
	# ld $@

$(OBJ_DIR):
	mkdir $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm $(NAME)
	rm test

re: fclean all

test: $(NAME) test.c
	$(CC) test.c -Wall -Wextra -lasm -L. -o test

.PHONY: all clean fclean re test
