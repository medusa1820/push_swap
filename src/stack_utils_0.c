/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musenov <musenov@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 16:41:53 by musenov           #+#    #+#             */
/*   Updated: 2023/05/14 18:39:03 by musenov          ###   ########.fr       */
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

t_node	*find_last_node(t_node *head)
{
	t_node	*current;

	current = head;
	while (current != NULL && current->next != NULL)
		current = current->next;
	return (current);
}
