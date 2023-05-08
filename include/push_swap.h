/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musenov <musenov@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 19:29:56 by musenov           #+#    #+#             */
/*   Updated: 2023/05/08 18:32:57 by musenov          ###   ########.fr       */
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
void	print_stack_reverse(t_node *node);
t_node	*ft_lstlast_ps(t_node *lst);
void	print_2d_array(char **str);

// exit_utils.c
void	error_message(void);
void	free_2d_array(char **str);
void	free_stack(t_node *head);
void	exit_util(t_node *head, char **input);
void	exit_util_sorted(t_node *head, char **input);

// input_ops.c
char	*ft_strjoin_ps(char const *s1, char const *s2);
char	*join_inputs(char **argv);
bool	ps_atoi_ln(const char *str, int *result);

// main.c
char	**prepare_input(char **argv);
void	init_stack(char **input, struct s_2stacks *two_stacks);
int		main(int argc, char **argv);

// push_command.c
void	pb(struct s_2stacks *two_stacks);
void	pa(struct s_2stacks *two_stacks);

// stack_ops.c
t_node	*create_node(int num);
void	add_node(t_node **head, int num);
int		is_duplicate(t_node *head, int num);
int		is_sorted(t_node *head);

// swap_commands.c
void	sa(struct s_2stacks *two_stacks);
void	sb(struct s_2stacks *two_stacks);
void	ss(struct s_2stacks *two_stacks);

#endif
