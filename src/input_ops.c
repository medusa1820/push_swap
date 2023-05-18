/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musenov <musenov@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 20:00:20 by musenov           #+#    #+#             */
/*   Updated: 2023/05/18 17:45:27 by musenov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	ft_atoi_push_swap(const char *str, int *result)
{
	int		i;
	int		sign;
	long	output;

	i = 0;
	sign = 1;
	if (str[0] == '+' || str[0] == '-')
	{
		if (str[0] == '-')
			sign = -1;
		i++;
	}
	if (str[i] == 0)
		return (0);
	output = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		output = (sign * (str[i++] - '0') + (output * 10));
		if (output > INT_MAX || output < INT_MIN)
			return (0);
		*result = output;
	}
	return (1);
}

void	bubble_sort(int arr[], int size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}
