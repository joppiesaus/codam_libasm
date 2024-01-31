NAME=libasm.a
SRC_DIR=src
OBJ_DIR=obj
ASM=nasm
CC=gcc
CFLAGS=-Wall -Wextra

HEADERS=include/libasm.h $(SRC_DIR)/libasm_testing.h
SRCS=$(addprefix $(SRC_DIR)/,ft_strlen.s ft_strcmp.s ft_strcpy.s ft_strdup.s ft_write.s ft_read.s)
TEST_SRCS=$(addprefix $(SRC_DIR)/,test.c test_util.c test_write.c)

OBJ=$(subst $(SRC_DIR),$(OBJ_DIR),$(SRCS:%.s=%.o))
TEST_OBJ=$(subst $(SRC_DIR),$(OBJ_DIR),$(TEST_SRCS:%.c=%.co))


all: $(NAME)

$(NAME): $(OBJ)
	ar -rcs $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.s | $(OBJ_DIR)
	$(ASM) -felf64 $< -o $@

# note the .co "c object" to distinguish from the .s files
$(OBJ_DIR)/%.co: $(SRC_DIR)/%.c $(NAME) $(HEADERS) | $(OBJ_DIR)
	$(CC) -c $(CFLAGS) -Iinclude -I$(SRC_DIR) -o $@ $<

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
