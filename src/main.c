/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musenov <musenov@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 19:27:51 by musenov           #+#    #+#             */
/*   Updated: 2023/05/07 19:09:24 by musenov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_node	*a;
	t_node	*b;

	// if (check_input(argc, argv))
	// 	return (EXIT_FAILURE);
	if (streamline_input(argv))
		error_message();
	// print_argv(argv);
	printf("reached end of main()\n");
	// system("leaks push_swap");
	return (0);
}

// 4 2 "3" 4 3 "25" 43 34 "7 3 2 8"