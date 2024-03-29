/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musenov <musenov@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 22:08:36 by htsang            #+#    #+#             */
/*   Updated: 2023/05/28 18:10:50 by musenov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <unistd.h>
# include <stdlib.h>

// char	*get_next_line(int fd);
// char	*ft_strncpy(char *dest, const char *src, size_t n);
// char	*ft_strljoin(char *target, char const *str, size_t len);
// char	*ft_strdup(const char *str);

//gnl_simple
// int		ft_strlen_gnl(char *string);
// char	*ft_strdup_gnl(char *string);
char	*get_next_line(int fd);

#endif