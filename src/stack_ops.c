/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musenov <musenov@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 16:41:53 by musenov           #+#    #+#             */
/*   Updated: 2023/05/07 15:13:50 by musenov          ###   ########.fr       */
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

// Function to convert a string to an integer
bool	ps_atoi_ln(const char *str, int *result)
{
	int		i;
	int		sign;
	long	temp;

	i = 0;
	sign = 1;
	temp = 0;
	if (str[0] == '+' || str[0] == '-')
	{
		if (str[0] == '-')
			sign = -1;
		i++;
	}
	if (str[i] == 0)
		return (false);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (false);
		temp = (sign * (str[i++] - '0') + (temp * 10));
		if (temp > INT_MAX || temp < INT_MIN)
			return (false);
		*result = temp;
	}
	return (true);
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
