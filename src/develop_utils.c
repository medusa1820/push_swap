/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   develop_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musenov <musenov@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 15:00:32 by musenov           #+#    #+#             */
/*   Updated: 2023/05/08 17:32:38 by musenov          ###   ########.fr       */
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
			printf("%c", argv[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

void	print_stack(t_node *node)
{
	while (node != NULL)
	{
		printf("%d -> ", node->num);
		node = node->next;
	}
	printf("NULL");
	printf("\n");
}

void	print_stack_reverse(t_node *node)
{
	node = ft_lstlast_ps(node);
	while (node != NULL)
	{
		printf("%d -> ", node->num);
		node = node->prev;
	}
	printf("NULL");
	printf("\n");
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

void	print_2d_array(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_putstr_fd(str[i], 1);
		ft_putchar_fd('\n', 1);
		i++;
	}
}
