NAME=libasm.a
TEST_NAME=test
SRC_DIR=src
OBJ_DIR=obj
ASM=nasm
CC=gcc
CFLAGS=-Wall -Wextra

# TODO: separate bonus compile

HEADERS=include/libasm.h $(SRC_DIR)/libasm_testing.h
SRCS=$(addprefix $(SRC_DIR)/,ft_strlen.s ft_strcmp.s ft_strcpy.s ft_strdup.s ft_write.s ft_read.s ft_list_push_front_bonus.s ft_list_size_bonus.s ft_list_sort_bonus.s)
TEST_SRCS=$(addprefix $(SRC_DIR)/,test.c test_util.c test_io.c test_bonus.c)

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
	rm $(TEST_NAME)

re: fclean all

$(TEST_NAME): $(NAME) $(TEST_OBJ)
	$(CC) $(TEST_OBJ) $(CFLAGS) -lasm -L. -o $@

.PHONY: all clean fclean re
