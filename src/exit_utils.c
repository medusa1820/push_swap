/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musenov <musenov@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 18:23:47 by musenov           #+#    #+#             */
/*   Updated: 2023/05/08 13:36:55 by musenov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_message(void)
{
	ft_putstr_fd("Error\n", 1);
	exit (EXIT_FAILURE);
}

void	free_2d_array(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free (str[i]);
		i++;
	}
	free(str);
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

void	exit_util(t_node *head, char **input)
{
	free_stack(head);
	free_2d_array(input);
	error_message();
}

void	exit_util_sorted(t_node *head, char **input)
{
	free_stack(head);
	free_2d_array(input);
	exit (EXIT_FAILURE);
}
