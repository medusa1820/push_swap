/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musenov <musenov@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 19:27:51 by musenov           #+#    #+#             */
/*   Updated: 2023/05/14 14:11:58 by musenov          ###   ########.fr       */
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

void	init_stack(char **input, struct s_2stacks *two_stacks, int *nr_nodes)
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
	// free_2d_array(input);
	two_stacks->stack_a = head;
	*nr_nodes = count_nodes(two_stacks->stack_a);
}

void	index_input(char **input, int nr_nodes, struct s_2stacks *two_stacks)
{
	int		i;
	int		num;
	int		*sorted_array;
	t_node	*cursor;

	i = 0;
	sorted_array = (int *)malloc(sizeof(int) * (nr_nodes + 1));
	while (input[i])
	{
		ps_atoi_ln(input[i], &num);
		sorted_array[i] = num;
		i++;
	}
	bubble_sort(sorted_array, nr_nodes);
	// ft_printf("Array after sorting: ");
	// for (i = 0; i <= nr_nodes; i++) {
	// 	ft_printf("%d ", sorted_array[i]);
	// }
	// ft_printf("\n");
	cursor = two_stacks->stack_a;
	while (cursor)
	{
		i = 0;
		while (i < nr_nodes)
		{
			if (cursor->num == sorted_array[i])
				cursor->index = i;
			i++;
		}
		cursor = cursor->next;
	}
	free_2d_array(input);
	free(sorted_array);
}

int	ft_sqrt(int number)
{
	int	i;

	if (number < 4)
		return (1);
	i = 2;
	while (i * i < number)
		i++;
	if (i * i > number)
	{
		if ((i * i - number) < ((i - 1) * (i - 1) + (-number)))
			return (i);
	}
	return (i - 1);
}

void	sort_stack(struct s_2stacks *two_stacks, int nr_nodes)
{
	int		i;
	int		range;

	range = ft_sqrt(nr_nodes) * 14 / 10;
	// ft_printf("range: %d\n", range);
	i = 0;
	while (two_stacks->stack_a)
	{
		if (two_stacks->stack_a->index <= i)
		{
			pb(two_stacks);
			rb(two_stacks);
			i++;
		}
		else if (two_stacks->stack_a->index <= i + range)
		{	
			pb(two_stacks);
			i++;
		}
		else
			ra(two_stacks);
		// cursor = cursor->next;
	}
}

int	count_r(t_node *stack, int index)
{
	int	counter;

	counter = 0;
	while (stack && stack->index != index)
	{
		stack = stack->next;
		counter++;
	}
	return (counter);
}

void	k_sort2(struct s_2stacks *two_stacks, int nr_nodes)
{
	int	rb_count;
	int	rrb_count;

	while (nr_nodes - 1 >= 0)
	{
		rb_count = count_r(two_stacks->stack_b, nr_nodes - 1);
		rrb_count = (nr_nodes + 3) - rb_count;
		if (rb_count <= rrb_count)
		{
			while (two_stacks->stack_b->index != nr_nodes - 1)
				rb(two_stacks);
			pa(two_stacks);
			nr_nodes--;
		}
		else
		{
			while (two_stacks->stack_b->index != nr_nodes - 1)
				rrb(two_stacks);
			pa(two_stacks);
			nr_nodes--;
		}
	}
}

void	test_instruction_call(struct s_2stacks *two_stacks)
{
	pb(two_stacks);
	rb(two_stacks);
	pb(two_stacks);
	ra(two_stacks);
}

int	main(int argc, char **argv)
{
	struct s_2stacks	two_stacks;
	char				**input;
	int					nr_nodes;

	two_stacks.stack_a = NULL;
	two_stacks.stack_b = NULL;
	input = prepare_input(argv);
	init_stack(input, &two_stacks, &nr_nodes);
	index_input(input, nr_nodes, &two_stacks);
	// print_stack(two_stacks.stack_a);
	// print_stack(two_stacks.stack_b);
	// ft_printf("nr_nodes: %d\n", nr_nodes);
	sort_stack(&two_stacks, nr_nodes);
	k_sort2(&two_stacks, nr_nodes);
	// test_instruction_call(&two_stacks);
	// print_stack(two_stacks.stack_a);
	// print_stack(two_stacks.stack_b);
	// print_stack_index(two_stacks.stack_a);
	// ft_printf("reached end of main()\n");
	free_stack(two_stacks.stack_a);
	free_stack(two_stacks.stack_b);
	// system("leaks push_swap");
	return (0);
}

// 4 2 "3" 4 3 "25" 43 34 "7 3 2 8"

