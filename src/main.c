/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musenov <musenov@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 19:27:51 by musenov           #+#    #+#             */
/*   Updated: 2023/05/08 13:37:17 by musenov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**prepare_input(char **argv)
{
	char	*input_joined;
	char	**split_input_joined;

	input_joined = join_inputs(argv);
	split_input_joined = ft_split(input_joined, ' ');
	free(input_joined);
	return (split_input_joined);
}

void	init_stack(char **input, struct s_2stacks *two_stacks)
{
	t_node	*head;
	int		i;
	int		num;

	head = NULL;
	i = 0;
	while (input[i])
	{
		if (!ps_atoi_ln(input[i], &num))
			exit_util(head, input);
		if (is_duplicate(head, num))
			exit_util(head, input);
		add_node(&head, num);
		i++;
	}
	if (is_sorted(head))
		exit_util_sorted(head, input);
	free_2d_array(input);
	two_stacks->stack_a = head;
}

int	main(int argc, char **argv)
{
	struct s_2stacks	two_stacks;
	char				**input;

	input = prepare_input(argv);
	init_stack(input, &two_stacks);
	print_argv(argv);
	print_stack(two_stacks.stack_a);
	free_stack(two_stacks.stack_a);
	printf("reached end of main()\n");
	system("leaks push_swap");
	return (0);
}

// 4 2 "3" 4 3 "25" 43 34 "7 3 2 8"