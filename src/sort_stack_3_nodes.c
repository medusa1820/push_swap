/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_3_nodes.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musenov <musenov@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 21:34:42 by musenov           #+#    #+#             */
/*   Updated: 2023/05/17 23:42:46 by musenov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*find_max_node_stack_a(struct s_2stacks *two_stacks)
{
	t_node	*current;
	t_node	*max_node;

	current = two_stacks->stack_a;
	max_node = current;
	while (current != NULL)
	{
		if (current->num > max_node->num)
			max_node = current;
		current = current->next;
	}
	return (max_node);
}

void	sort_stack_3_nodes(struct s_2stacks *two_stacks)
{
	t_node	*max_node;

	max_node = find_max_node_stack_a(two_stacks);
	if (two_stacks->stack_a == max_node)
		ra(two_stacks);
	if (two_stacks->stack_a->next == max_node)
		rra(two_stacks);
	if (two_stacks->stack_a->num > two_stacks->stack_a->next->num)
		sa(two_stacks);
}
