/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate_commands.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musenov <musenov@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 20:38:34 by musenov           #+#    #+#             */
/*   Updated: 2023/05/12 16:12:23 by musenov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate_a(struct s_2stacks *two_stacks)
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
			tail->prev->next = NULL;
			tail->prev = NULL;
			tail->next = head;
			two_stacks->stack_a = tail;
			head->prev = tail;
		}
	}
}

void	reverse_rotate_b(struct s_2stacks *two_stacks)
{
	t_node	*head;
	t_node	*tail;

	if (two_stacks->stack_b && two_stacks->stack_b->next)
	{
		if (count_nodes(two_stacks->stack_b) == 2)
			swap_a(two_stacks);
		else
		{
			head = two_stacks->stack_b;
			tail = find_last_node(two_stacks->stack_b);
			tail->prev->next = NULL;
			tail->prev = NULL;
			tail->next = head;
			two_stacks->stack_b = tail;
			head->prev = tail;
		}
	}
}

void	rra(struct s_2stacks *two_stacks)
{
	reverse_rotate_a(two_stacks);
	ft_printf("rra\n");
}

void	rrb(struct s_2stacks *two_stacks)
{
	reverse_rotate_b(two_stacks);
	ft_printf("rrb\n");
}

void	rrr(struct s_2stacks *two_stacks)
{
	reverse_rotate_a(two_stacks);
	reverse_rotate_b(two_stacks);
	ft_printf("rrr\n");
}
