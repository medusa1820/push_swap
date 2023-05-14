/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musenov <musenov@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 17:49:42 by musenov           #+#    #+#             */
/*   Updated: 2023/05/14 18:39:09 by musenov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_duplicate(t_node *head, int num)
{
	t_node	*current;

	current = head;
	while (current != NULL)
	{
		if (current->num == num)
			return (1);
		current = current->next;
	}
	return (0);
}

int	is_sorted(t_node *head)
{
	t_node	*current;

	if (!head || !head->next)
		return (1);
	current = head;
	while (current->next)
	{
		if (current->num > current->next->num)
			return (0);
		current = current->next;
	}
	return (1);
}
