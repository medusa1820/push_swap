/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musenov <musenov@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 19:02:31 by musenov           #+#    #+#             */
/*   Updated: 2023/05/18 19:48:13 by musenov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	struct s_2stacks	two_stacks;
	char				**input;
	int					nr_nodes;

	two_stacks.stack_a = NULL;
	two_stacks.stack_b = NULL;
	input = prepare_input(argv);
	init_stack(input, &two_stacks, &nr_nodes);
	index_input(input, nr_nodes, &two_stacks);
	if (process_instructions(&two_stacks) == 1)
		exit_util(two_stacks.stack_a, input);
	if (is_sorted(two_stacks.stack_a))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	// ft_error(&a, &b, 0);
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
