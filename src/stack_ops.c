/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musenov <musenov@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 16:41:53 by musenov           #+#    #+#             */
/*   Updated: 2023/05/12 17:06:30 by musenov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*create_node(int num)
{
	t_node	*new_node;

	new_node = malloc(sizeof(*new_node));
	if (new_node == NULL)
		exit(EXIT_FAILURE);
	new_node->num = num;
	new_node->prev = NULL;
	new_node->next = NULL;
	return (new_node);
}

void	add_node(t_node **head, int num)
{
	t_node	*new_node;
	t_node	*current;

	new_node = create_node(num);
	if (*head == NULL)
	{
		*head = new_node;
		return ;
	}
	current = *head;
	while (current->next != NULL)
		current = current->next;
	current->next = new_node;
	new_node->prev = current;
}

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

int	count_nodes(t_node *stack)
{
	t_node	*node;
	int		count;

	node = stack;
	count = 0;
	while (node)
	{
		count++;
		node = node->next;
	}
	return (count);
}
