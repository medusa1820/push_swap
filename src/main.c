/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musenov <musenov@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 19:27:51 by musenov           #+#    #+#             */
/*   Updated: 2023/05/18 16:25:30 by musenov          ###   ########.fr       */
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
		if (!ft_atoi_push_swap(input[i], &num))
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

void	index_input(char **input, int nr_nodes, struct s_2stacks *two_stacks)
{
	int		i;
	int		*sorted_array;
	t_node	*cursor;

	i = 0;
	sorted_array = (int *)malloc(sizeof(int) * (nr_nodes + 1));
	while (input[i])
	{
		ft_atoi_push_swap(input[i], &sorted_array[i]);
		i++;
	}
	bubble_sort(sorted_array, nr_nodes);
	cursor = two_stacks->stack_a;
	while (cursor)
	{
		i = 0;
		while (i < nr_nodes)
		{
			if (cursor->num == sorted_array[i])
				cursor->index = i;
			i++;
		}
		cursor = cursor->next;
	}
	free(sorted_array);
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
		sort_stack_5_nodes(&two_stacks);
	else
	{
		sort_stack_to_b(&two_stacks, nr_nodes);
		sort_stack_to_a(&two_stacks, nr_nodes);
	}
	free_2d_array(input);
	free_stack(two_stacks.stack_a);
	free_stack(two_stacks.stack_b);
	return (0);
}

// system("leaks push_swap");
