/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musenov <musenov@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 20:00:20 by musenov           #+#    #+#             */
/*   Updated: 2023/05/07 19:17:11 by musenov          ###   ########.fr       */
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

// Function to convert a string to an integer
bool	ps_atoi_ln(const char *str, int *result)
{
	int		i;
	int		sign;
	long	temp;

	i = 0;
	sign = 1;
	temp = 0;
	if (str[0] == '+' || str[0] == '-')
	{
		if (str[0] == '-')
			sign = -1;
		i++;
	}
	if (str[i] == 0)
		return (false);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (false);
		temp = (sign * (str[i++] - '0') + (temp * 10));
		if (temp > INT_MAX || temp < INT_MIN)
			return (false);
		*result = temp;
	}
	return (true);
}
