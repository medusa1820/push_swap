/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musenov <musenov@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 19:56:31 by musenov           #+#    #+#             */
/*   Updated: 2023/05/19 15:20:51 by musenov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H
# include "push_swap.h"
// # include "../lib/ft_printf/ft_printf.h"

// checker.c
int		main(int argc, char **argv);
int		process_instructions(struct s_2stacks *two_stacks);
void	free_split(char **split);
int		do_instructions(struct s_2stacks *two_stacks, char *op);
void	push_b(struct s_2stacks *two_stacks);
void	push_a(struct s_2stacks *two_stacks);
void	init_stack_checker(char **input, struct s_2stacks *two_stacks, int *nr_nodes);
void	exit_util_checker(struct s_2stacks *two_stacks, char **input);


// get_next_line_utils.c
char	*ft_strnew(size_t size);
char	*ft_strdup_gnl(char *s1);
char	*ft_strjoin_gnl(char const *s1, char const *s2);

// get_next_line.c
char	*get_next_line(int fd);
char	*check_left(char **left, char **line, char **p_n);
int		read_to_buf(char **left, char **line, char **p_n, int *fd);

#endif