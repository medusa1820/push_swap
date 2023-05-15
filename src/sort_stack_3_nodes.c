/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_3_nodes.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musenov <musenov@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 21:34:42 by musenov           #+#    #+#             */
/*   Updated: 2023/05/15 13:46:25 by musenov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*find_max_node(struct s_2stacks *two_stacks)
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

	max_node = find_max_node(two_stacks);
	if (two_stacks->stack_a == max_node)
		ra(two_stacks);
	if (two_stacks->stack_a->next == max_node)
		rra(two_stacks);
	if (two_stacks->stack_a->num > two_stacks->stack_a->next->num)
		sa(two_stacks);
}

void	circular_sort(struct s_2stacks *two_stacks)
{
	t_node	*max_node;
	int		position_max_node;

	pb(two_stacks);
	pb(two_stacks);
	max_node = find_max_node(two_stacks);
	sort_stack_3_nodes(two_stacks);
	while (two_stacks->stack_b)
	{
		if (two_stacks->stack_b->num > max_node->num)
			pa(two_stacks);
		if (two_stacks->stack_b->num < max_node->num && \
			two_stacks->stack_b->num > max_node->prev->num)
		{
			rra(two_stacks);
			pa(two_stacks);
		}
		if (two_stacks->stack_b->num < max_node->prev->num && \
			two_stacks->stack_b->num > two_stacks->stack_a->num)
		{
			ra(two_stacks);
			pa(two_stacks);
		}
		if (two_stacks->stack_b->num < two_stacks->stack_a->num)
			pa(two_stacks);
	}
	position_max_node = find_position_max_node(two_stacks);
	while (position_max_node != 4)
	{
		if (position_max_node >= 2)
			rra(two_stacks);
		else
			ra(two_stacks);
		position_max_node = find_position_max_node(two_stacks);
	}
}

int	find_position_max_node(struct s_2stacks *two_stacks)
{
	int		i;
	t_node	*max_node;

	max_node = find_max_node(two_stacks);
	i = 0;
	while (max_node)
	{
		max_node = max_node->next;
		i++;
	}
	return (4 - (i - 1));
}
