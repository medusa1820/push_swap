/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_commands.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musenov <musenov@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 16:05:13 by musenov           #+#    #+#             */
/*   Updated: 2023/05/08 17:56:39 by musenov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb(struct s_2stacks *two_stacks)
{
	t_node	*temp;

	if (!two_stacks->stack_a)
		return ;
	temp = two_stacks->stack_a;
	two_stacks->stack_a = two_stacks->stack_a->next;
	if (two_stacks->stack_a)
		two_stacks->stack_a->prev = NULL;
	if (!two_stacks->stack_b)
	{
		two_stacks->stack_b = temp;
		two_stacks->stack_b->next = NULL;
	}
	else
	{
		temp->next = two_stacks->stack_b;
		two_stacks->stack_b->prev = temp;
		two_stacks->stack_b = temp;
	}
	ft_printf("pb\n");
}

void	pa(struct s_2stacks *two_stacks)
{
	t_node	*temp;

	if (!two_stacks->stack_b)
		return ;
	temp = two_stacks->stack_b;
	two_stacks->stack_b = two_stacks->stack_b->next;
	if (two_stacks->stack_b)
		two_stacks->stack_b->prev = NULL;
	if (!two_stacks->stack_a)
	{
		two_stacks->stack_a = temp;
		two_stacks->stack_a->next = NULL;
	}
	else
	{
		temp->next = two_stacks->stack_a;
		two_stacks->stack_a->prev = temp;
		two_stacks->stack_a = temp;
	}
	ft_printf("pa\n");
}
