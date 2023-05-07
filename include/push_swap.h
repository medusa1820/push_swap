/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musenov <musenov@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 19:29:56 by musenov           #+#    #+#             */
/*   Updated: 2023/05/07 23:34:06 by musenov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "get_next_line.h"
# include <stdbool.h>
# include <limits.h>
# include <math.h>
# include <fcntl.h>

# include "../lib/ft_printf/libft/libft.h"
# include "../lib/ft_printf/ft_printf.h"

typedef struct s_node
{
	int				num;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

struct s_2stacks
{
	t_node	*stack_a;
	t_node	*stack_b;
};

// develop_utils.c
void	print_argv(char **argv);
void	print_stack(t_node *node);
void	print_2d_array(char **str);

// input_ops.c
int		check_input(int argc, char **argv);
char	*join_inputs(char **argv);
char	*ft_strjoin_ps(char const *s1, char const *s2);
int		streamline_input(char **argv);
void	free_2d_array(char **str);

// input_utils.c
void	error_message(void);

// main.c
char	**prepare_input(char **argv);
void	init_stack(char **input, struct s_2stacks *two_stacks);
int		main(int argc, char **argv);

// stack_ops.c
t_node	*create_node(int num);
void	add_node(t_node **head, int num);
bool	ps_atoi_ln(const char *str, int *result);
void	free_stack(t_node *head);
int		stack_valid(t_node *head);
int		duplicate(t_node *head, int num);

#endif
