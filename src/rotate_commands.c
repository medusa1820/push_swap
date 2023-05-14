/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_commands.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musenov <musenov@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 16:19:53 by musenov           #+#    #+#             */
/*   Updated: 2023/05/14 13:06:08 by musenov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(struct s_2stacks *two_stacks)
{
	t_node	*head;
	t_node	*tail;

	if (two_stacks->stack_a && two_stacks->stack_a->next)
	{
		if (count_nodes(two_stacks->stack_a) == 2)
			swap_a(two_stacks);
		else
		{
			head = two_stacks->stack_a;
			tail = find_last_node(two_stacks->stack_a);
			head->next->prev = NULL;
			two_stacks->stack_a = head->next;
			head->next = NULL;
			head->prev = tail;
			tail->next = head;
		}
	}
}

void	rotate_b(struct s_2stacks *two_stacks)
{
	t_node	*head;
	t_node	*tail;

	if (two_stacks->stack_b && two_stacks->stack_b->next)
	{
		if (count_nodes(two_stacks->stack_b) == 2)
			swap_b(two_stacks);
		else
		{
			head = two_stacks->stack_b;
			tail = find_last_node(two_stacks->stack_b);
			head->next->prev = NULL;
			two_stacks->stack_b = head->next;
			head->next = NULL;
			head->prev = tail;
			tail->next = head;
		}
	}
}

void	ra(struct s_2stacks *two_stacks)
{
	rotate_a(two_stacks);
	ft_printf("ra\n");
}

void	rb(struct s_2stacks *two_stacks)
{
	rotate_b(two_stacks);
	ft_printf("rb\n");
}

void	rr(struct s_2stacks *two_stacks)
{
	rotate_a(two_stacks);
	rotate_b(two_stacks);
	ft_printf("rr\n");
}
