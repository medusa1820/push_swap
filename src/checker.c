/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musenov <musenov@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 19:02:31 by musenov           #+#    #+#             */
/*   Updated: 2023/05/18 22:14:02 by musenov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	main(int argc, char **argv)
{
	struct s_2stacks	two_stacks;
	char				**input;
	int					nr_nodes;

	two_stacks.stack_a = NULL;
	two_stacks.stack_b = NULL;
	if (argc < 2)
		exit(1);
	input = prepare_input(argv);
	init_stack_checker(input, &two_stacks, &nr_nodes);
	index_input(input, nr_nodes, &two_stacks);
	if (process_instructions(&two_stacks) == 1)
		exit_util(two_stacks.stack_a, input);
	if (is_sorted(two_stacks.stack_a))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	// ft_error(&a, &b, 0);
	free_2d_array(input);
	free_stack(two_stacks.stack_a);
	free_stack(two_stacks.stack_b);
	return (0);
}

int	process_instructions(struct s_2stacks *two_stacks)
{
	char	**split;
	char	*line;
	int		i;

	line = get_next_line(STDIN_FILENO);
	while (line)
	{
		split = ft_split(line, ' ');
		i = -1;
		while (split[++i])
			if (do_instructions(two_stacks, split[i]) == 1)
				return (1);
		free(line);
		free_split(split);
		line = get_next_line(STDIN_FILENO);
	}
	return (0);
}

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

int	do_instructions(struct s_2stacks *two_stacks, char *op)
{
	if (ft_strncmp(op, "sa\n", 3) == 0)
		swap_a(two_stacks);
	else if (ft_strncmp(op, "sb\n", 3) == 0)
		swap_b(two_stacks);
	else if (ft_strncmp(op, "ss\n", 3) == 0)
	{
		swap_a(two_stacks);
		swap_b(two_stacks);
	}
	else if (ft_strncmp(op, "ra\n", 3) == 0)
		rotate_a(two_stacks);
	else if (ft_strncmp(op, "rra\n", 4) == 0)
		reverse_rotate_a(two_stacks);
	else if (ft_strncmp(op, "rb\n", 3) == 0)
		rotate_b(two_stacks);
	else if (ft_strncmp(op, "rrb\n", 4) == 0)
		reverse_rotate_b(two_stacks);
	else if (ft_strncmp(op, "rr\n", 3) == 0)
	{
		rotate_a(two_stacks);
		rotate_b(two_stacks);
	}
	else if (ft_strncmp(op, "rrr\n", 4) == 0)
	{
		reverse_rotate_a(two_stacks);
		reverse_rotate_b(two_stacks);
	}
	else if (ft_strncmp(op, "pa\n", 3) == 0)
		push_a(two_stacks);
	else if (ft_strncmp(op, "pb\n", 3) == 0)
		push_b(two_stacks);
	else
		error_message();
	return (0);
}

void	push_b(struct s_2stacks *two_stacks)
{
	t_node	*temp;

	if (!two_stacks->stack_a)
		return ;
	temp = two_stacks->stack_a;
	two_stacks->stack_a = two_stacks->stack_a->next;
	if (two_stacks->stack_a)
		two_stacks->stack_a->prev = NULL;
	if (!two_stacks->stack_b)
	{
		two_stacks->stack_b = temp;
		two_stacks->stack_b->next = NULL;
	}
	else
	{
		temp->next = two_stacks->stack_b;
		two_stacks->stack_b->prev = temp;
		two_stacks->stack_b = temp;
	}
}

void	push_a(struct s_2stacks *two_stacks)
{
	t_node	*temp;

	if (!two_stacks->stack_b)
		return ;
	temp = two_stacks->stack_b;
	two_stacks->stack_b = two_stacks->stack_b->next;
	if (two_stacks->stack_b)
		two_stacks->stack_b->prev = NULL;
	if (!two_stacks->stack_a)
	{
		two_stacks->stack_a = temp;
		two_stacks->stack_a->next = NULL;
	}
	else
	{
		temp->next = two_stacks->stack_a;
		two_stacks->stack_a->prev = temp;
		two_stacks->stack_a = temp;
	}
}

void	init_stack_checker(char **input, struct s_2stacks *two_stacks, int *nr_nodes)
{
	t_node	*head;
	int		i;
	int		num;

	head = NULL;
	i = 0;
	while (input[i])
	{
		if (!ft_atoi_push_swap(input[i], &num))
			exit_util(head, input);
		if (is_duplicate(head, num))
			exit_util(head, input);
		add_node(&head, num);
		i++;
	}
	// if (is_sorted(head))
	// 	exit_util_sorted(head, input);
	two_stacks->stack_a = head;
	*nr_nodes = count_nodes(two_stacks->stack_a);
}
