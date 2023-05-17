/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_5_nodes.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musenov <musenov@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 23:42:50 by musenov           #+#    #+#             */
/*   Updated: 2023/05/18 00:06:02 by musenov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack_5_nodes(struct s_2stacks *two_stacks)
{
	pb(two_stacks);
	pb(two_stacks);
	sort_stack_3_nodes(two_stacks);
	if (two_stacks->stack_b->num < two_stacks->stack_a->num || \
		two_stacks->stack_b->num > two_stacks->stack_a->next->next->num)
		pa(two_stacks);
	else if (two_stacks->stack_b->num > two_stacks->stack_a->num && \
			two_stacks->stack_b->num < two_stacks->stack_a->next->num)
	{
		ra(two_stacks);
		pa(two_stacks);
	}
	else if (two_stacks->stack_b->num > two_stacks->stack_a->next->num && \
			two_stacks->stack_b->num < two_stacks->stack_a->next->next->num)
	{
		rra(two_stacks);
		pa(two_stacks);
	}
	add_fifth_node(two_stacks);
	sort_after_add_fifth(two_stacks);
}

void	sort_after_add_fourth(struct s_2stacks *two_stacks)
{
	t_node	max_node;
	int		position;

	position = find_position_max_node(two_stacks);
	if (position == 0)
		ra(two_stacks);
	if (position == 1)
	{
		rra(two_stacks);
		rra(two_stacks);
	}
	if (position == 2)
		rra(two_stacks);
}

void	add_fifth_node(struct s_2stacks *two_stacks)
{
	if (initial_check_before_5(two_stacks))
		return ;
	if (two_stacks->stack_b->num < two_stacks->stack_a->num || \
		two_stacks->stack_b->num > two_stacks->stack_a->next->next->next->num)
		pa(two_stacks);
	else if (two_stacks->stack_b->num > two_stacks->stack_a->num && \
			two_stacks->stack_b->num < two_stacks->stack_a->next->num)
	{
		ra(two_stacks);
		pa(two_stacks);
	}
	else if (two_stacks->stack_b->num > two_stacks->stack_a->next->num && \
			two_stacks->stack_b->num < two_stacks->stack_a->next->next->num)
	{
		ra(two_stacks);
		ra(two_stacks);
		pa(two_stacks);
	}
	else if (two_stacks->stack_b->num > two_stacks->stack_a->next->next->num && \
		two_stacks->stack_b->num < two_stacks->stack_a->next->next->next->num)
	{
		rra(two_stacks);
		pa(two_stacks);
	}
}

void	sort_after_add_fifth(struct s_2stacks *two_stacks)
{
	t_node	max_node;
	int		position;

	position = find_position_max_node(two_stacks);
	if (position == 0)
		ra(two_stacks);
	if (position == 1)
	{
		ra(two_stacks);
		ra(two_stacks);
	}
	if (position == 2)
	{
		rra(two_stacks);
		rra(two_stacks);
	}
	if (position == 3)
		rra(two_stacks);
}
