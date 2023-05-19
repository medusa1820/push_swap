/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musenov <musenov@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 19:27:51 by musenov           #+#    #+#             */
/*   Updated: 2023/05/19 15:38:17 by musenov          ###   ########.fr       */
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
	system("leaks push_swap");
	return (0);
}

