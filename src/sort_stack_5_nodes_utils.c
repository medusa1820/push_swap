/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_5_nodes_utils.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musenov <musenov@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 23:42:50 by musenov           #+#    #+#             */
/*   Updated: 2023/05/18 00:05:25 by musenov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_position_max_node(struct s_2stacks *two_stacks)
{
	int		i;
	t_node	*max_node;

	max_node = find_max_node_stack_a(two_stacks);
	i = -1;
	while (max_node)
	{
		max_node = max_node->prev;
		i++;
	}
	return (i);
}

int	initial_check_before_5(struct s_2stacks *two_stacks)
{
	if (two_stacks->stack_b->num < two_stacks->stack_a->num && \
		two_stacks->stack_b->num > two_stacks->stack_a->next->next->next->num)
	{
		pa(two_stacks);
		return (1);
	}
	else
		sort_after_add_fourth(two_stacks);
	return (0);
}
