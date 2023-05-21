/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musenov <musenov@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 19:02:31 by musenov           #+#    #+#             */
/*   Updated: 2023/05/21 17:47:46 by musenov          ###   ########.fr       */
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
		exit_util_checker(&two_stacks, input);
	if (is_sorted(two_stacks.stack_a) && \
		nr_nodes == count_nodes(two_stacks.stack_a))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_2d_array(input);
	free_stack(two_stacks.stack_a);
	free_stack(two_stacks.stack_b);
	// system("leaks checker");
	return (0);
}

int	process_instructions(struct s_2stacks *two_stacks)
{
	char	*buffer;
	int		read_len;

	buffer = (char *)malloc(4);
	if (buffer == NULL)
	{
		ft_printf("Error allocating memory for buffer in checker");
		return (-1);
	}
	read_len = read(0, buffer, 4);
	while (read_len > 0)
	{
		if (do_instructions(two_stacks, buffer) == 1)
		{
			free(buffer);
			return (1);
		}
		read_len = read(0, buffer, 4);
	}
	free(buffer);
	return (0);
}

int	do_instructions(struct s_2stacks *two_stacks, char *instruction)
{
	if (ft_strncmp(instruction, "sa\n", 3) == 0)
		swap_a(two_stacks);
	else if (ft_strncmp(instruction, "sb\n", 3) == 0)
		swap_b(two_stacks);
	else if (ft_strncmp(instruction, "ss\n", 3) == 0)
		ss_checker(two_stacks);
	else if (ft_strncmp(instruction, "pa\n", 3) == 0)
		push_a(two_stacks);
	else if (ft_strncmp(instruction, "pb\n", 3) == 0)
		push_b(two_stacks);
	else if (ft_strncmp(instruction, "ra\n", 3) == 0)
		rotate_a(two_stacks);
	else if (ft_strncmp(instruction, "rb\n", 3) == 0)
		rotate_b(two_stacks);
	else if (ft_strncmp(instruction, "rr\n", 3) == 0)
		rr_checker(two_stacks);
	else if (ft_strncmp(instruction, "rra\n", 4) == 0)
		reverse_rotate_a(two_stacks);
	else if (ft_strncmp(instruction, "rrb\n", 4) == 0)
		reverse_rotate_b(two_stacks);
	else if (ft_strncmp(instruction, "rrr\n", 4) == 0)
		rrr_checker(two_stacks);
	else
		return (1);
	return (0);
}

void	init_stack_checker(char **input, struct s_2stacks *two_stacks, \
		int *nr_nodes)
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
	two_stacks->stack_a = head;
	*nr_nodes = count_nodes(two_stacks->stack_a);
}
