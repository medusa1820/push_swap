/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musenov <musenov@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 16:39:55 by musenov           #+#    #+#             */
/*   Updated: 2023/05/21 16:56:22 by musenov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	exit_util_checker(struct s_2stacks *two_stacks, char **input)
{
	free_stack(two_stacks->stack_a);
	free_stack(two_stacks->stack_b);
	free_2d_array(input);
	error_message();
}
