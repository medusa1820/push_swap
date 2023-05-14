/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musenov <musenov@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 18:36:41 by musenov           #+#    #+#             */
/*   Updated: 2023/05/14 19:39:27 by musenov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_sqrt(int number)
{
	int	i;

	if (number < 4)
		return (1);
	i = 2;
	while (i * i < number)
		i++;
	if (i * i > number)
	{
		if ((i * i - number) < ((i - 1) * (i - 1) + (-number)))
			return (i);
	}
	return (i - 1);
}

int	count_r(t_node *stack, int index)
{
	int	counter;

	counter = 0;
	while (stack && stack->index != index)
	{
		stack = stack->next;
		counter++;
	}
	return (counter);
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
		ps_atoi_ln(input[i], &sorted_array[i]);
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

void	sort_stack_2b(struct s_2stacks *two_stacks, int nr_nodes)
{
	int		i;
	int		range;

	range = ft_sqrt(nr_nodes) * 1.5;
	i = 0;
	while (two_stacks->stack_a)
	{
		if (two_stacks->stack_a->index <= i)
		{
			pb(two_stacks);
			rb(two_stacks);
			i++;
		}
		else if (two_stacks->stack_a->index <= i + range)
		{
			pb(two_stacks);
			i++;
		}
		else
			ra(two_stacks);
	}
}

void	sort_stack_2a(struct s_2stacks *two_stacks, int nr_nodes)
{
	int	rb_count;
	int	rrb_count;

	while (nr_nodes - 1 >= 0)
	{
		rb_count = count_r(two_stacks->stack_b, nr_nodes - 1);
		rrb_count = (nr_nodes + 3) - rb_count;
		if (rb_count <= rrb_count)
		{
			while (two_stacks->stack_b->index != nr_nodes - 1)
				rb(two_stacks);
			pa(two_stacks);
			nr_nodes--;
		}
		else
		{
			while (two_stacks->stack_b->index != nr_nodes - 1)
				rrb(two_stacks);
			pa(two_stacks);
			nr_nodes--;
		}
	}
}
