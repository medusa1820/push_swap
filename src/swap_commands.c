/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_commands.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musenov <musenov@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 17:55:08 by musenov           #+#    #+#             */
/*   Updated: 2023/05/14 16:32:13 by musenov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(struct s_2stacks *two_stacks)
{
	t_node	*temp;

	if (two_stacks->stack_a && two_stacks->stack_a->next)
	{
		temp = two_stacks->stack_a->next;
		two_stacks->stack_a->next = two_stacks->stack_a->next->next;
		if (two_stacks->stack_a->next)
			two_stacks->stack_a->next->prev = two_stacks->stack_a;
		temp->next = two_stacks->stack_a;
		temp->prev = NULL;
		two_stacks->stack_a->prev = temp;
		two_stacks->stack_a = temp;
	}
}

void	swap_b(struct s_2stacks *two_stacks)
{
	t_node	*temp;

	if (two_stacks->stack_b && two_stacks->stack_b->next)
	{
		temp = two_stacks->stack_b->next;
		two_stacks->stack_b->next = two_stacks->stack_b->next->next;
		if (two_stacks->stack_b->next)
			two_stacks->stack_b->next->prev = two_stacks->stack_b;
		temp->next = two_stacks->stack_b;
		temp->prev = NULL;
		two_stacks->stack_b->prev = temp;
		two_stacks->stack_b = temp;
	}
}

void	sa(struct s_2stacks *two_stacks)
{
	swap_a(two_stacks);
	ft_printf("sa\n");
}

void	sb(struct s_2stacks *two_stacks)
{
	swap_b(two_stacks);
	ft_printf("sb\n");
}

void	ss(struct s_2stacks *two_stacks)
{
	swap_a(two_stacks);
	swap_b(two_stacks);
	ft_printf("ss\n");
}
