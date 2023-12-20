NAME=libasm.a
ASM=nasm
SRC_DIR=src # TODO
SRCS=$(wildcard *.s)
OBJ_DIR=obj
OBJ=$(SRCS:%.s=$(OBJ_DIR)/%.o)

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

re: fclean all

.PHONY: all clean fclean re
