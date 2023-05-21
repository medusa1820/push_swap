NAME := push_swap
BONUS_NAME := checker

CC := gcc

CFLAGS = -Wall -Werror -Wextra -g -fsanitize=address
# CFLAGS = -Wall -Werror -Wextra -g
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

BONUS	:=	checker_main.c \
			checker_utils_0.c \
			checker_utils_1.c \
			develop_utils_0.c \
			develop_utils_1.c \
			exit_utils.c \
			input_ops.c \
			main_utils.c \
			rev_rotate_commands.c \
			rotate_commands.c \
			stack_utils_0.c \
			stack_utils_1.c \
			swap_commands.c

HEADER = -I ./include -I ../LeakSanitizer 

LIBFT_PRINTF_DIR = ./lib/ft_printf
LIBFT_PRINTF = ./lib/ft_printf/libftprintf.a

libft_printf:
	${MAKE} -C $(LIBFT_PRINTF_DIR) -j

clean:
	${MAKE} -C $(LIBFT_PRINTF_DIR) fclean

all: libft_printf
	${MAKE} $(NAME) -j

fclean: clean
	rm -f $(NAME)

re: fclean all

bonus:
	${MAKE} $(BONUS_NAME) -j

bonus_fclean: clean
	rm -f $(BONUS_NAME)

re_bonus: bonus_fclean bonus

re_all: re re_bonus

$(NAME):
	$(CC) $(LDFLAGS) $(addprefix $(SRC_DIR),$(SRC)) $(HEADER) $(LIBFT_PRINTF) \
	-o $(NAME)
# $(CC) $(CFLAGS) $(addprefix $(SRC_DIR),$(SRC)) $(HEADER) $(LIBFT_PRINTF) \
	-o $(NAME)
# $(CC) $(LDFLAGS) $(addprefix $(SRC_DIR),$(SRC)) $(HEADER) $(LIBFT_PRINTF) \
	-o $(NAME) -L ../LeakSanitizer -llsan -lc++ -Wno-gnu-include-next
# $(CC) $(CFLAGS) $(addprefix $(SRC_DIR),$(SRC)) $(HEADER) $(LIBFT_PRINTF) \
	-o $(NAME) -L ../LeakSanitizer -llsan -lc++ -Wno-gnu-include-next

$(BONUS_NAME):
	$(CC) $(LDFLAGS) $(addprefix $(SRC_DIR),$(BONUS)) $(HEADER) $(LIBFT_PRINTF) \
	-o $(BONUS_NAME)
# $(CC) $(CFLAGS) $(addprefix $(SRC_DIR),$(BONUS)) $(HEADER) $(LIBFT_PRINTF) \
	-o $(BONUS_NAME)
# $(CC) $(LDFLAGS) $(addprefix $(SRC_DIR),$(BONUS)) $(HEADER) $(LIBFT_PRINTF) \
	-o $(BONUS_NAME) -L ../LeakSanitizer -llsan -lc++ -Wno-gnu-include-next
# $(CC) $(CFLAGS) $(addprefix $(SRC_DIR),$(BONUS)) $(HEADER) $(LIBFT_PRINTF) \
	-o $(BONUS_NAME) -L ../LeakSanitizer -llsan -lc++ -Wno-gnu-include-next

.PHONY: libft_printf clean all fclean re bonus bonus_fclean re_bonus re_all
