/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estrong <estrong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 01:47:52 by estrong           #+#    #+#             */
/*   Updated: 2022/03/11 19:26:38 by estrong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 9

char	*get_next_line(int fd);
char	*ft_read(int fd, char *line);
char	*ft_before(char	*line);
char	*ft_after(char	*line);

char	*g_ft_strchr(const char *s, int n);
size_t	g_ft_strlen(const char *s);
char	*g_ft_strdup(const char *s1);
char	*g_ft_substr(char *s, unsigned int start, size_t len);
char	*g_ft_strjoin(char *s1, char *s2);

# endif
#endif
