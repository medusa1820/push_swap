/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musenov <musenov@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 19:56:31 by musenov           #+#    #+#             */
/*   Updated: 2023/05/21 17:05:34 by musenov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H
# include "push_swap.h"

// checker_main.c
int		main(int argc, char **argv);
int		process_instructions(struct s_2stacks *two_stacks);
int		do_instructions(struct s_2stacks *two_stacks, char *instruction);
void	init_stack_checker(char **input, struct s_2stacks *two_stacks, \
		int *nr_nodes);

// checker_utils_0.c
void	push_b(struct s_2stacks *two_stacks);
void	push_a(struct s_2stacks *two_stacks);
void	ss_checker(struct s_2stacks *two_stacks);
void	rr_checker(struct s_2stacks *two_stacks);
void	rrr_checker(struct s_2stacks *two_stacks);

// checker_utils_1.c
void	exit_util_checker(struct s_2stacks *two_stacks, char **input);

#endif
