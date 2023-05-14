/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   develop_utils_0.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musenov <musenov@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 15:00:32 by musenov           #+#    #+#             */
/*   Updated: 2023/05/14 18:45:19 by musenov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_argv(char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			ft_printf("%c", argv[i][j]);
			j++;
		}
		ft_printf("\n");
		i++;
	}
}

void	print_stack(t_node *node)
{
	t_node	*cursor;

	cursor = node;
	while (cursor != NULL)
	{
		ft_printf("%d -> ", cursor->num);
		cursor = cursor->next;
	}
	ft_printf("NULL");
	ft_printf("\n");
}

void	print_stack_index(t_node *node)
{
	t_node	*cursor;

	cursor = node;
	while (cursor != NULL)
	{
		ft_printf("%d -> ", cursor->index);
		cursor = cursor->next;
	}
	ft_printf("index");
	ft_printf("\n");
}

void	print_stack_reverse(t_node *node)
{
	node = ft_lstlast_ps(node);
	while (node != NULL)
	{
		ft_printf("%d -> ", node->num);
		node = node->prev;
	}
	ft_printf("NULL");
	ft_printf("\n");
}

t_node	*ft_lstlast_ps(t_node *lst)
{
	while (lst)
	{
		if ((*lst).next == 0)
			return (lst);
		lst = (*lst).next;
	}
	return (lst);
}
