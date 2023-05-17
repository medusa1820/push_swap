/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musenov <musenov@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 19:27:51 by musenov           #+#    #+#             */
/*   Updated: 2023/05/17 19:03:34 by musenov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**prepare_input(char **argv)
{
	char	*input_joined;
	char	**split_input_joined;

	input_joined = join_inputs(argv);
	split_input_joined = ft_split(input_joined, ' ');
	free(input_joined);
	return (split_input_joined);
}

void	init_stack(char **input, struct s_2stacks *two_stacks, int *nr_nodes)
{
	t_node	*head;
	int		i;
	int		num;

	head = NULL;
	i = 0;
	while (input[i])
	{
		if (!ps_atoi_ln(input[i], &num))
			exit_util(head, input);
		if (is_duplicate(head, num))
			exit_util(head, input);
		add_node(&head, num);
		i++;
	}
	if (is_sorted(head))
		exit_util_sorted(head, input);
	two_stacks->stack_a = head;
	*nr_nodes = count_nodes(two_stacks->stack_a);
}

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
	if (nr_nodes == 2)
		sa(&two_stacks);
	else if (nr_nodes == 3)
		sort_stack_3_nodes(&two_stacks);
	else if (nr_nodes == 5)
		sort_four_five_elements(&two_stacks);
	else
	{
		sort_stack_2b(&two_stacks, nr_nodes);
		sort_stack_2a(&two_stacks, nr_nodes);
	}
	free_2d_array(input);
	free_stack(two_stacks.stack_a);
	free_stack(two_stacks.stack_b);
	return (0);
}

// system("leaks push_swap");

// bash push_swap_tester/tester.sh ../push_swap 100-102 100
