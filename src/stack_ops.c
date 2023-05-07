/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musenov <musenov@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 16:41:53 by musenov           #+#    #+#             */
/*   Updated: 2023/05/07 23:39:00 by musenov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Function to create a new node
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

// Function to add a node to the end of the list
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

void	free_stack(t_node *head)
{
	t_node	*current;
	t_node	*next_node;

	current = head;
	while (current != NULL)
	{
		next_node = current->next;
		free(current);
		current = next_node;
	}
}

int	stack_valid(t_node *head)
{
	t_node	*current;

	current = head;
	while (current != NULL)
	{
		if (current->num != 0)
			return (1);
		current = current->next;
	}
	return (0);
}

int	duplicate(t_node *head, int num)
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

int is_sorted(t_node *head) {
	if (!head || !head->next) {
		// empty list or list with only one node is considered sorted
		return 1;
	}

	t_node *current = head;
	while (current->next) {
		if (current->num > current->next->num) {
			// list is not sorted
			return 0;
		}
		current = current->next;
	}

	// list is sorted
	return 1;
}
