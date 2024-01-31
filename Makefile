NAME=libasm.a
ASM=nasm
CC=gcc
CFLAGS=-Wall -Wextra

SRC_DIR=src # TODO
HEADERS=libasm.h
SRCS=ft_strlen.s ft_strcmp.s ft_strcpy.s ft_strdup.s ft_write.s ft_read.s
TEST_SRCS=test.c

OBJ_DIR=obj
TEST_OBJ_DIR=c
OBJ=$(SRCS:%.s=$(OBJ_DIR)/%.o)
TEST_OBJ=$(TEST_SRCS:%.c=$(OBJ_DIR)/$(TEST_OBJ_DIR)/%.o)


all: $(NAME)

$(NAME): $(OBJ)
	ar -rcs $@ $^

$(OBJ_DIR)/%.o: %.s | $(OBJ_DIR)
	$(ASM) -felf64 $< -o $@

$(OBJ_DIR)/$(TEST_OBJ_DIR)/%.o: %.c $(NAME) $(HEADERS) | $(OBJ_DIR)/$(TEST_OBJ_DIR)
	$(CC) -c -o $@ $(CFLAGS) $<

$(OBJ_DIR)/$(TEST_OBJ_DIR): | $(OBJ_DIR)
	mkdir $@

$(OBJ_DIR):
	mkdir $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm $(NAME)
	rm test

re: fclean all

test: $(NAME) $(TEST_OBJ)
	$(CC) $(TEST_OBJ) $(CFLAGS) -lasm -L. -o $@

.PHONY: all clean fclean re
