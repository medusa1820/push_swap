/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musenov <musenov@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 19:29:56 by musenov           #+#    #+#             */
/*   Updated: 2023/05/21 17:08:00 by musenov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
// # include <limits.h>
// # include <math.h>
// # include <fcntl.h>

// # include "../lib/ft_printf/libft/libft.h"
# include "../lib/ft_printf/ft_printf.h"

typedef struct s_node
{
	int				num;
	int				index;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

struct s_2stacks
{
	t_node	*stack_a;
	t_node	*stack_b;
};

// develop_utils_0.c
void	print_argv(char **argv);
void	print_stack(t_node *node);
void	print_stack_index(t_node *node);
void	print_stack_reverse(t_node *node);
t_node	*ft_lstlast_ps(t_node *lst);

// develop_utils_1.c
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
int		ft_atoi_push_swap(const char *str, int *result);
void	bubble_sort(int arr[], int size);

// main_utils.c
char	**prepare_input(char **argv);
void	init_stack(char **input, struct s_2stacks *two_stacks, int *nr_nodes);
void	index_input(char **input, int nr_nodes, struct s_2stacks *two_stacks);

// main.c
int		main(int argc, char **argv);

// push_commands.c
void	pb(struct s_2stacks *two_stacks);
void	pa(struct s_2stacks *two_stacks);

// rev_rotate_commands.c
void	reverse_rotate_a(struct s_2stacks *two_stacks);
void	reverse_rotate_b(struct s_2stacks *two_stacks);
void	rra(struct s_2stacks *two_stacks);
void	rrb(struct s_2stacks *two_stacks);
void	rrr(struct s_2stacks *two_stacks);

// rotate_commands.c
void	rotate_a(struct s_2stacks *two_stacks);
void	rotate_b(struct s_2stacks *two_stacks);
void	ra(struct s_2stacks *two_stacks);
void	rb(struct s_2stacks *two_stacks);
void	rr(struct s_2stacks *two_stacks);

// sort_stack_3_nodes.c
t_node	*find_max_node_stack_a(struct s_2stacks *two_stacks);
void	sort_stack_3_nodes(struct s_2stacks *two_stacks);

// sort_stack_5_nodes_utils.c
int		find_position_max_node(struct s_2stacks *two_stacks);
int		initial_check_before_5(struct s_2stacks *two_stacks);

// sort_stack_5_nodes.c
void	sort_stack_5_nodes(struct s_2stacks *two_stacks);
void	sort_after_add_fourth(struct s_2stacks *two_stacks);
void	add_fifth_node(struct s_2stacks *two_stacks);
void	sort_after_add_fifth(struct s_2stacks *two_stacks);

// sort_stack.c
int		ft_sqrt(int number);
void	sort_stack_to_b(struct s_2stacks *two_stacks, int nr_nodes);
void	sort_stack_to_a(struct s_2stacks *two_stacks, int nr_nodes);
int		rotations_nr(t_node *stack, int index);

// stack_utils_0.c
t_node	*create_node(int num);
void	add_node(t_node **head, int num);
int		count_nodes(t_node *stack);
t_node	*find_last_node(t_node *head);

// stack_utils_1.c
int		is_duplicate(t_node *head, int num);
int		is_sorted(t_node *head);

// swap_commands.c
void	swap_a(struct s_2stacks *two_stacks);
void	swap_b(struct s_2stacks *two_stacks);
void	sa(struct s_2stacks *two_stacks);
void	sb(struct s_2stacks *two_stacks);
void	ss(struct s_2stacks *two_stacks);

#endif
