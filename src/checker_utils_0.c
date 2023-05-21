/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils_0.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musenov <musenov@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 16:39:55 by musenov           #+#    #+#             */
/*   Updated: 2023/05/21 16:56:31 by musenov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	push_b(struct s_2stacks *two_stacks)
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
}

void	push_a(struct s_2stacks *two_stacks)
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
}

void	ss_checker(struct s_2stacks *two_stacks)
{
	swap_a(two_stacks);
	swap_b(two_stacks);
}

void	rr_checker(struct s_2stacks *two_stacks)
{
	rotate_a(two_stacks);
	rotate_b(two_stacks);
}

void	rrr_checker(struct s_2stacks *two_stacks)
{
	reverse_rotate_a(two_stacks);
	reverse_rotate_b(two_stacks);
}
