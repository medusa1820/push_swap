/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_3_nodes.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musenov <musenov@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 21:34:42 by musenov           #+#    #+#             */
/*   Updated: 2023/05/17 19:19:06 by musenov          ###   ########.fr       */
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

void	sort_four_five_elements(struct s_2stacks *two_stacks)
{
	pb(two_stacks);
	pb(two_stacks);
	if (count_nodes(two_stacks->stack_a) == 3)
		sort_stack_3_nodes(two_stacks);
	else
	{
		if (two_stacks->stack_a->num > two_stacks->stack_a->next->num)
			sa(two_stacks);
	}
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
	if (count_nodes(two_stacks->stack_a) == 3)
		sort_stack_3_nodes(two_stacks);
	else
		rotate_after_sort_4(two_stacks);
	if (two_stacks->stack_b)
	{
		
		sort_fifth_element(two_stacks);
		rotate_after_sort_5(two_stacks);
	}
}

int	find_position_max_node(struct s_2stacks *two_stacks)
{
	int		i;
	t_node	*max_node;

	max_node = find_max_node_stack_a(two_stacks);
	i = 0;
	while (max_node)
	{
		max_node = max_node->next;
		i++;
	}
	return (4 - (i - 1));
}

void	rotate_after_sort_4(struct s_2stacks *two_stacks)
{
	t_node	max_node;
	int		position;

	position = find_position_max_node(two_stacks);
	// ft_printf("position: %d", position);
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

void	sort_fifth_element(struct s_2stacks *two_stacks)
{
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

void	rotate_after_sort_5(struct s_2stacks *two_stacks)
{
	t_node	max_node;
	int		position;

	position = find_position_max_node(two_stacks);
	// ft_printf("position: %d", position);
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
