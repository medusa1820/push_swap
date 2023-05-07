/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musenov <musenov@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 20:00:20 by musenov           #+#    #+#             */
/*   Updated: 2023/05/07 19:05:30 by musenov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_input(int argc, char **argv)
{
	if (argc == 1)
		return (EXIT_FAILURE);
	else if (argc == 2 && argv[1][0] == '\0')
		return (EXIT_FAILURE);
	else
		return (EXIT_SUCCESS);
}

char	*join_inputs(char **argv)
{
	char	*input_total;
	int		i;

	input_total = ft_strdup("");
	i = 1;
	while (argv[i])
	{
		input_total = ft_strjoin_ps(input_total, argv[i]);
		i++;
	}
	return (input_total);
}

char	*ft_strjoin_ps(char const *s1, char const *s2)
{
	char	*s3;
	size_t	i_s12;
	size_t	i_s3;

	if (!s1 || !s2)
		return (free ((char *)s1), NULL);
	s3 = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 2));
	if (!s3)
		return (free ((char *)s1), NULL);
	i_s3 = 0;
	i_s12 = 0;
	while (*(s1 + i_s12) != '\0')
		*(s3 + i_s3++) = *(s1 + i_s12++);
	i_s12 = 0;
	while (*(s2 + i_s12) != '\0')
		*(s3 + i_s3++) = *(s2 + i_s12++);
	*(s3 + i_s3) = ' ';
	*(s3 + i_s3 + 1) = '\0';
	free ((char *)s1);
	return (s3);
}

int	streamline_input(char **argv)
{
	t_node	*head;
	int		i;
	int		num;
	char	*input_total;
	char	**split_input_total;

	input_total = join_inputs(argv);
	split_input_total = ft_split(input_total, ' ');
	head = NULL;
	i = 0;
	while (split_input_total[i])
	{
		if (!ps_atoi_ln(split_input_total[i], &num))
			return (EXIT_FAILURE);
		add_node(&head, num);
		i++;
	}
	// print_list(head);
	free_stack(head);
	free(input_total);
	// print_2d_array(split_input_total);
	free_2d_array(split_input_total);
	return (EXIT_SUCCESS);
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
