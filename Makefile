NAME := push_swap
BONUS_NAME := checker

CC := gcc

CFLAGS = -Wall -Werror -Wextra -g -fsanitize=address
LDFLAGS = -flto -O3 -march=nocona -g

SRC_DIR	=	./src/

SRC		:=	develop_utils_0.c \
			develop_utils_1.c \
			exit_utils.c \
			input_ops.c \
			main_utils.c \
			main.c \
			push_commands.c \
			rev_rotate_commands.c \
			rotate_commands.c \
			sort_stack_3_nodes.c \
			sort_stack_5_nodes_utils.c \
			sort_stack_5_nodes.c \
			sort_stack.c \
			stack_utils_0.c \
			stack_utils_1.c \
			swap_commands.c

BONUS	:=	develop_utils_0.c \
			develop_utils_1.c \
			checker.c \
			get_next_line_utils.c \
			get_next_line.c \
			main_utils.c \
			input_ops.c \
			stack_utils_0.c \
			stack_utils_1.c \
			exit_utils.c \
			rev_rotate_commands.c \
			rotate_commands.c \
			swap_commands.c

HEADER = -I ./include -I ../LeakSanitizer 

LIBFT_PRINTF_DIR = ./lib/ft_printf
LIBFT_PRINTF = ./lib/ft_printf/libftprintf.a

all: libft_printf
	${MAKE} $(NAME) -j

libft_printf:
	${MAKE} -C $(LIBFT_PRINTF_DIR) -j

$(NAME):
# $(CC) $(LDFLAGS) $(addprefix $(SRC_DIR),$(SRC)) $(HEADER) $(LIBFT_PRINTF) \
	-o $(NAME)
	$(CC) $(LDFLAGS) $(addprefix $(SRC_DIR),$(SRC)) $(HEADER) $(LIBFT_PRINTF) \
	-o $(NAME) -L ../LeakSanitizer -llsan -lc++ -Wno-gnu-include-next

clean:
	${MAKE} -C $(LIBFT_PRINTF_DIR) fclean

fclean: clean
	rm -f $(NAME) $(BONUS_NAME)

re: fclean all

bonus:
	${MAKE} $(BONUS_NAME) -j

$(BONUS_NAME):
# $(CC) $(LDFLAGS) $(addprefix $(SRC_DIR),$(BONUS)) $(HEADER) $(LIBFT_PRINTF) \
	-o $(BONUS_NAME)
	$(CC) $(CFLAGS) $(addprefix $(SRC_DIR),$(BONUS)) $(HEADER) $(LIBFT_PRINTF) \
	-o $(BONUS_NAME) -L ../LeakSanitizer -llsan -lc++ -Wno-gnu-include-next

.PHONY: all clean fclean re bonus
