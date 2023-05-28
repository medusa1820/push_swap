/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musenov <musenov@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 17:01:45 by musenov           #+#    #+#             */
/*   Updated: 2023/05/28 18:40:09 by musenov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	int		i;
	int		rd;
	char	character;
	char	*buffer;

	i = 0;
	rd = 0;
	buffer = malloc(100000);
	if (BUFFER_SIZE <= 0)
		return (NULL);
	rd = read(fd, &character, BUFFER_SIZE - BUFFER_SIZE + 1);
	while (rd > 0)
	{
		buffer[i++] = character;
		if (character == '\n')
			break ;
		rd = read(fd, &character, BUFFER_SIZE - BUFFER_SIZE + 1);
	}
	buffer[i] = '\0';
	if (rd == -1 || i == 0 || (!buffer[i - 1] && !rd))
		return (free(buffer), NULL);
	return (buffer);
}

// int		i = 0;
// 	int		rd = 0;
// 	char	character;
// 	char	*buffer = malloc(100000);

// int	ft_strlen_gnl(char *string)
// {
// 	int	count;

// 	count = 0;
// 	while (string[count])
// 		count++;
// 	return (count);
// }

// char	*ft_strdup_gnl(char *string)
// {
// 	int		i;
// 	int		size;
// 	char	*duplicate;

// 	i = 0;
// 	size = ft_strlen_gnl(string);
// 	duplicate = malloc(sizeof(char) * (size + 1));
// 	if (!duplicate)
// 		return (0);
// 	while (string[i])
// 	{
// 		duplicate[i] = string[i];
// 		i++;
// 	}
// 	duplicate[i] = '\0';
// 	return (duplicate);
// }

// char	*get_next_line(int fd)
// {
// 	char	buffer;
// 	char	line[7000000];
// 	int		b;
// 	int		i;

// 	if (fd < 0 || BUFFER_SIZE <= 0)
// 		return (NULL);
// 	i = 0;
// 	b = read(fd, &buffer, 1);
// 	while (b > 0)
// 	{
// 		line[i++] = buffer;
// 		if (buffer == '\n')
// 			break ;
// 		b = read(fd, &buffer, 1);
// 	}
// 	line[i] = '\0';
// 	if (b <= 0 && i == 0)
// 		return (NULL);
// 	return (ft_strdup_gnl(line));
// }
