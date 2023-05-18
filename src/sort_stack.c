/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musenov <musenov@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 18:36:41 by musenov           #+#    #+#             */
/*   Updated: 2023/05/18 16:22:13 by musenov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_sqrt(int n)
{
	int	x;
	int	y;

	if (n <= 1)
		return (n);
	x = n / 2;
	while (1)
	{
		y = (x + (n / x)) / 2;
		if (y >= x)
			return (x);
		x = y;
	}
}


void	sort_stack_to_b(struct s_2stacks *two_stacks, int nr_nodes)
{
	int		i;
	int		range;

	range = ft_sqrt(nr_nodes) * 1.5;
	// ft_printf("sqrt: %d\n", ft_sqrt(nr_nodes));
	// ft_printf("sqrt: %d\n", range / 1.5);
	// ft_printf("sqrt: %d\n", range);
	// print_stack_index(two_stacks->stack_a);
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

void	sort_stack_to_a(struct s_2stacks *two_stacks, int nr_nodes)
{
	int	rb_rotations_nr;
	int	rrb_rotations_nr;

	while (nr_nodes > 0)
	{
		rb_rotations_nr = rotations_nr(two_stacks->stack_b, nr_nodes - 1);
		rrb_rotations_nr = nr_nodes - rb_rotations_nr;
		if (rb_rotations_nr > rrb_rotations_nr)
		{
			while (two_stacks->stack_b->index != nr_nodes - 1)
				rrb(two_stacks);
			pa(two_stacks);
			nr_nodes--;
		}
		else
		{
			while (two_stacks->stack_b->index != nr_nodes - 1)
				rb(two_stacks);
			pa(two_stacks);
			nr_nodes--;
		}
	}
}

int	rotations_nr(t_node *stack_b, int max_node_index)
{
	int	i;

	i = 0;
	while (stack_b && stack_b->index != max_node_index)
	{
		stack_b = stack_b->next;
		i++;
	}
	return (i);
}
