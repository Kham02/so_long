/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estrong <estrong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 13:44:55 by estrong           #+#    #+#             */
/*   Updated: 2021/10/20 23:15:56 by estrong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int n)
{
	int	i;

	i = 0;
	while ((unsigned char)s[i] != (unsigned char)n && s[i] != '\0' )
		i++;
	if ((unsigned char)s[i] == (unsigned char)n)
		return ((char *)(&s[i]));
	return (NULL);
}
