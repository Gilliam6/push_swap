SRCS_LIST = push_swap.c pushes.c\
		reverse_rotate.c\
 		rotate.c stack.c\
 		swaps.c utils.c
SRCS_DIR = srcs/
SRCS = $(addprefix $(SRCS_DIR), $(SRCS_LIST))

OBJ_DIR = objects/
OBJ_LIST = $(patsubst %.c, %.o, $(SRCS_LIST))
OBJ = $(addprefix $(OBJ_DIR), $(OBJ_LIST))

LIBFT = libft/libft.a

HEADER = includes/push_swap.h
HEADER_LIB = includes/libft.h

INCLUDES = -I$(HEADER) -I$(HEADER_LIB)

NAME = push_swap

CFLAGS = -Wall -Wextra -Werror
RM = rm -f

# COLORS

GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJ)
		@gcc $(CFLAGS) libft/libft.a $(INCLUDES) $(OBJ) -o $(NAME)
		@echo "\n$(NAME):$(GREEN).o files were created$(RESET)"
		@echo "$(NAME): $(GREEN)$(NAME) was created$(RESET)"

$(OBJ_DIR):
		@mkdir -p $(OBJ_DIR)
		@echo "$(NAME): $(GREEN)$(OBJ_DIR) was created$(RESET)"

$(OBJ_DIR)%.o: $(SRCS_DIR)%.c $(HEADER) $(HEADER_LIB)
		@gcc $(CFLAGS) -c $(INCLUDES) $< -o $@
		@echo "$(GREEN)/$(RESET)\c"

clean:
		@echo "$(NAME):$(GREEN) libft is cleaned$(RESET)"
		@echo "$(NAME):$(GREEN) objects dirs are cleaned$(RESET)"
		@rm -rf objects

fclean: clean
		@$(RM) $(NAME)

re : fclean all

.PHONY: all clean fclean re
